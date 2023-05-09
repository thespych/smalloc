#ifndef SMALLOC_H
#define SMALLOC_H

#include <stddef.h>
#include <stdint.h>

/*
 Macro declarations
 ===================================================================
*/

#define METADATA_SIZE (sizeof(metadata));
#define MINIMUM_BLOCK_SIZE (METADATA_SIZE + 1);

#define MIN_SMALL_REGION_SIZE (150);
#define MIN_MEDIUM_REGION_SIZE (500);
#define MIN_LARGE_REGION_SIZE (1000);

/*
 Struct and enum declarations
 ===================================================================
*/

typedef struct chunk_metadata {
    enum region region;
    unsigned long size;
    struct chunk_metadata *next;
} metadata;

typedef enum chunk_region {
    SMALL,
    MEDIUM,
    LARGE,
} region;

typedef enum error {
    NO_ERROR,
    OUT_OF_MEMORY,
    REQUEST_TOO_LARGE,
} error_type;

/*
 Function declarations
 ===================================================================
*/

void *smalloc(size_t size);

void sfree(void *ptr);

void *srealloc(void *ptr, size_t size);

void *scalloc(size_t n, size_t size);

/*
 Helper function declarations
 ===================================================================
*/

metadata *find_right_chunk(metadata *chunk);

metadata *find_left_chunk(metadata *chunk);

void coalesce_chunks(metadata *left_chunk, metadata *right_chunk);

metadata *split_chunk(metadata *chunk, size_t size);

void add_chunk(metadata *chunk);

void remove_chunk(metadata *chunk);

metadata *find_best_fit(size_t size);




#endif // endif for SMALLOC_H
