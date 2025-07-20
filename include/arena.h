#ifndef ARENA_H
#define ARENA_H

#include <allocator.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct ArenaBlock {
	size_t size;
	size_t bytes_left;
	void *block;
	struct ArenaBlock *next;
} ArenaBlock;

typedef struct {
	Allocator allocator;
	ArenaBlock *head_block;
	ArenaBlock *current_block;
} ArenaAllocator;

extern ArenaAllocator *init_arena(size_t block_size);
extern void deinit_arena(ArenaAllocator *arena);

#endif
