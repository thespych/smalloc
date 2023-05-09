===================================================================================
                                    smalloc
===================================================================================

smalloc is a general purpose memory allocator optimized for efficient searching and
reduced fragmentation. Implementing a free list, smalloc manages allocations by
maintaining sections for small, medium, and large requests for memory to reduce
fragementation. Each section contains its own binary search tree with self-merging
nodes to provide efficient access.

Created by Sean Spych
2023
