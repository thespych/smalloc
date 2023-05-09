#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "smalloc.h"





//===================================================================================
//                              helper functions
//===================================================================================

/*
 Helper Function: find_right_chunk()
 Given an in-use chunk's metadata, we search the chunk's regional free list to find if
 there exists a free chunk in the list directly to its right. If no such chunk is found,
 null is returned.
*/
metadata *find_right_chunk(metadata *chunk) {



}

/*
 Helper Function: find_left_chunk()
 Given an in-use chunk's metadata, we search the chunk's regional free list to find if
 there exists a free chunk in the list directly to its left. If no such chunk is found,
 null is returned.
*/
metadata *find_left_chunk(metadata *chunk) {



}

/*
 Helper Function: coalesce_chunks()
 Given two adjacent chunks in the same regional list, the chunks are coalesced together
 to form one large chunk. The left chunk's metadata is used as the new coalesced chunk.
*/
void coalesce_chunks(metadata *left_chunk, metadata *right_chunk) {



}

/*
 Helper Function: split_chunk()
 Given a chunk in the list, we remove and return part of the chunk up until the specified
 size. The remaining part of the chunk, if it's large enough, is made into a new chunk in
 the list.
*/
metadata *split_chunk(metadata *chunk, size_t size) {



}

/*
 Helper Function: add_chunk()
 Adds an in-use chunk back into its regional list
*/
void add_chunk(metadata *chunk) {



}

/*
 Helper Function: remove_chunk()
 Removes a chunk from its regional list
*/
void remove_chunk(metadata *chunk) {



}

/*
Helper Function: find_best_fit()
Finds a block of best fit in the entire list. If a block of exact fit cannot be found,
then the next smallest block is used. If no adequate block is found in the regional
list, then other regional lists are searched. If no adequate block at all is found,
null is returned.
*/
metadata *find_best_fit(size_t size) {





}

//===================================================================================
//                              smalloc functions
//===================================================================================

/*
Function: smalloc()
Begins by searching in the size's corresponding regional list for an available chunk.
If no chunk is available in that regional list, the other regional lists are searched.
If no chunk is still available, a call to ssbrk() is made. If ssbrk() fails, then null
is returned.
*/
void *smalloc(size_t size) {



}

/*
Function: sfree()
Works by first trying to add in a chunk back into its corresponding regional list. The
metadata's region is referenced to determine which regional list the chunk should be
placed in.
*/
void sfree(void *ptr) {



}

/*
Function: srealloc()
If resizing to a smaller chunk, and the resize is less than the minimum region size, then
search other regional lists for a free chunk, then copy over the values. If greater than the
minimum region size, then just split the block normally.
If resizing to a larger chunk, and the resize calls for greater than the next region up's
minimum size, then search larger regions for free chunks. If not, then check to see if there
is an adjacent right block. If there is, absorb that block into the new block. If not, then
search the regional list for other blocks.
*/
void *srealloc(void *ptr, size_t size) {



}

/*
Function: scalloc()
Works identical to smalloc(), but zeros out all memory locations
*/
void *scalloc(size_t n, size_t size) {



}


