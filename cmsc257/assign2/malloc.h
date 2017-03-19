struct block_meta {
        size_t size;
        size_t actual_size; // Remove after implimenting splitting and merging
        struct block_meta *next;
        int free;
        int magic; // @SEE `malloc-tutorial` documentation, this should be removed in non-debug mode.
};

#define META_SIZE sizeof(struct block_meta)

struct block_meta *find_free_block(struct block_meta **last, size_t size);

struct block_meta *request_space(struct block_meta * last, size_t size);

struct block_meta *get_block_ptr(void *ptr);

void *my_malloc(size_t size);

void my_free(void *ptr);

void *my_calloc(size_t nelem, size_t elsize);

void *my_realloc(void *ptr, size_t size);

void print_malloc_usage();

void split(struct block_meta *block, size_t size);
