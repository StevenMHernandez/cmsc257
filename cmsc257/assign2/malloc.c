#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#include "malloc.h"

void *global_base = NULL;

struct block_meta *find_parent_block(struct block_meta *child) {
        struct block_meta *parent = global_base;

        while (parent && parent->next != child) {
                parent = parent->next;
        }

        return parent;
}

struct block_meta *find_free_block(struct block_meta **last, size_t size) {
        struct block_meta *current = global_base;
        struct block_meta *best_fit = NULL;

        while (current) {
                // if current is free and current is large enough
                // and either best_fit hasn't been found yet or current->size is better than best_fit->size
                if (current->free && current->size >= size && (!best_fit || current->size < best_fit->size)) {
                        best_fit = current;
                }
                *last = current;
                current = current->next;
        }

        return best_fit;
}

struct block_meta *request_space(struct block_meta * last, size_t size) {
        size_t padded_size = size % 8 ? size : (size - (size % 8) + 8);

        struct block_meta *block;
        block = sbrk(0);
        void *request = sbrk(padded_size + META_SIZE);

        assert((void*)block == request); // Not thread safe.

        if (request == (void*) -1) {
                return NULL; // sbrk failed.
        }

        if (last) {
                last->next = block;
        }

        block->size = padded_size;
        block->actual_size = size;
        block->next = NULL;
        block->free = 0;

        return block;
}

void *my_malloc(size_t size) {
        struct block_meta *block;

        if (size <= 0) {
                return NULL;
        }

        if (!global_base) { // If nothing else has been alloc'd yet:
                block = request_space(NULL, size);
                if (!block) {
                        return NULL;
                }
                global_base = block;
        } else {
                struct block_meta *last = global_base;
                block = find_free_block(&last, size);
                if (!block) { // If there are no free blocks found:
                        block = request_space(last, size);
                        if (!block) {
                                return NULL;
                        }
                } else {
                        block->free = 0;
                        block->actual_size = size;

                        split(block, size);
                }
        }

        // REMEMBER: we are first placing `block_meta` before the real data
        // incrementing by 1 actual increments our address by size_of(block_meta)
        return (block + 1);
}

// if the block size is greater than the size we are requesting + META_SIZE + 1,
// then we should split to prevent memory leaks.
// NOTE: if there is not enough space for the meta block though, we are still losing space.
void split(struct block_meta *block, size_t size) {
        if (block->size > size + META_SIZE + 1) {
                // new_block will be placed at the pointer of block + the size a that block's metadata and the size allocated in the malloc request.
                struct block_meta *new_block = ((void*)block) + META_SIZE + size;

                new_block->size = block->size - size - META_SIZE;
                new_block->actual_size = new_block->size;
                new_block->next = block->next;
                new_block->free = 1;

                block->size = size;
                block->actual_size = size;
                block->next = new_block;
        }
}

struct block_meta *get_block_ptr(void *ptr) {
        return (struct block_meta*)ptr - 1;
}

void my_free(void *ptr) {
        if (!ptr) {
                return;
        }

        struct block_meta *block_ptr = get_block_ptr(ptr);
        assert(block_ptr->free == 0);
        block_ptr->free = 1;

        // Handle merging with child (next)
        if (block_ptr->next && block_ptr->next->free) {
                block_ptr->size += block_ptr->next->size + META_SIZE;
                block_ptr->next = block_ptr->next->next;
        }
        // Handle merging with parent (prev)
        struct block_meta *parent_ptr = find_parent_block(block_ptr);
        if (parent_ptr && parent_ptr->free) {
                parent_ptr->size += block_ptr->size + META_SIZE;
                parent_ptr->next = block_ptr->next;
        }

        block_ptr->actual_size = block_ptr->size;
}

void *my_calloc(size_t nelem, size_t elsize) {
        size_t size = nelem *elsize;
        void *ptr = my_malloc(size);
        memset(ptr, 0, size);
        return ptr;
}

void *my_realloc(void *ptr, size_t size) {
        if (!ptr) { // If null, act like malloc:
                return my_malloc(size);
        }

        struct block_meta *block_ptr = get_block_ptr(ptr);
        if (block_ptr->size >= size) {
                split(block_ptr, size);
                block_ptr->actual_size = size;
                return ptr;
        } else if (block_ptr->next->free && block_ptr->size + META_SIZE + block_ptr->next->size >= size) {
                // if the next block is free, we can join the blocks to have an even larger sized chunk
                block_ptr->size += META_SIZE + block_ptr->next->size;

                block_ptr->next = block_ptr->next->next;

                // we can now do the same exact process as above
                split(block_ptr, size);
                block_ptr->actual_size = size;
                return ptr;
        }

        void *new_ptr;
        new_ptr = my_malloc(size);
        if (!new_ptr) {
                return NULL;
        }

        memcpy(new_ptr, ptr, block_ptr->size);

        my_free(ptr);

        return new_ptr;
}

void print_malloc_usage() {
        if (!global_base) {
                printf("Nothing is currently allocated.");
                return;
        }

        struct block_meta *current = global_base;

        printf("pointer     |  free? |  size  | realsize | mem-leak | leak reason\n");

        while (current) {
            int leak = current->size - current->actual_size;
                printf("%p | %6d | %6zu | %8zu | %8lu | ", current, current->free, current->size, current->actual_size, current->free ? current->size : leak);
                if (current->size - current->actual_size > 0 || current->free) {
                        printf(current->free ? "Memory is free" : "META_SIZE > free space");
                }
                printf("\n");
                current = current->next;
        }
}
