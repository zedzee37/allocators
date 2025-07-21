#include "arena.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void arena_alloc_block(ArenaAllocator *arena) {
	size_t size = arena->current_block->size;

	ArenaBlock *new_block = malloc(sizeof(ArenaBlock));
	new_block->size = size;
	new_block->bytes_left = size;
	new_block->block = malloc(size);

	arena->current_block->next = new_block;
	arena->current_block = new_block;
	arena->current_block->next = NULL;
}

void *arena_alloc(Allocator *allocator, size_t size) {
	ArenaAllocator *arena = (ArenaAllocator *)allocator;

	if (size > arena->current_block->size) {
		perror("Size is greater than the base block size!");
		return NULL;
	}

	if (size > arena->current_block->bytes_left) {
		arena_alloc_block(arena);
	}

	size_t current_idx = arena->current_block->size - arena->current_block->bytes_left;
	arena->current_block->bytes_left -= size;
	return arena->current_block->block + current_idx;
}

void arena_free(Allocator *allocator, void *addr) {}

void *arena_realloc(Allocator *allocator, void *addr, size_t new_size) { return NULL; }

ArenaAllocator *init_arena(size_t block_size) {
	ArenaAllocator *arena = malloc(sizeof(ArenaAllocator));
	arena->head_block = malloc(sizeof(ArenaBlock));
	arena->head_block->block = malloc(block_size);
	arena->head_block->next = NULL;
	arena->head_block->size = block_size;
	arena->head_block->bytes_left = block_size;
	arena->current_block = arena->head_block;

	Allocator allocator = {
		.alloc_func = arena_alloc,
		.free_func = arena_free,
		.realloc_func = arena_realloc,
	};
	arena->allocator = allocator;

	return arena;
}

void deinit_arena(ArenaAllocator *arena) {
	ArenaBlock *current = arena->head_block;

	while (current) {
		free(current->block);
		
		ArenaBlock *tmp = current;
		current = current->next;
		
		free(tmp);
	}

	free(arena);
}
