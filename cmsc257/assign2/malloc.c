#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "malloc.h"

void *global_base = NULL;

struct block_meta *find_free_block(struct block_meta **last, size_t size) {
        struct block_meta *current = global_base;

        while (current && !(current->free && current->size >= size)) {
                *last = current;
                current = current->next;
        }

        return current;
}

struct block_meta *request_space(struct block_meta * last, size_t size) {
        struct block_meta *block;
        block = sbrk(0);
        void *request = sbrk(size + META_SIZE);

        assert((void*)block == request); // Not thread safe.

        if (request == (void*) -1) {
                return NULL; // sbrk failed.
        }

        if (last) {
                last->next = block;
        }

        block->size = size;
        block->next = NULL;
        block->free = 0;
        block->magic = 0x12345678;

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
                        block->magic = 0x77777777;
                }
        }

        // REMEMBER: we are first placing `block_meta` before the real data
        // incrementing by 1 actual increments our address by size_of(block_meta)
        return (block + 1);
}

struct block_meta *get_block_ptr(void *ptr) {
        return (struct block_meta*)ptr - 1;
}

void my_free(void *ptr) {
        if (!ptr) {
                return;
        }

        // TODO: handle merging and splitting
        struct block_meta *block_ptr = get_block_ptr(ptr);
        assert(block_ptr->free == 0);
        assert(block_ptr->magic == 0x77777777 || block_ptr->magic == 0x12345678);
        block_ptr->free = 1;
        block_ptr->magic = 0x55555555;
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
