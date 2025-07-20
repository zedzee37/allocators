#include "allocator.h"
#include <arena.h>
#include <stdio.h>
#include <test_util.h>

int main() {
	ArenaAllocator *arena = init_arena(512);
	EXPECT(arena != NULL);

	int *a = allocator_alloc(ALLOCATOR(arena), sizeof(int));
	*a = 10;
	EXPECT(*a == 10);

	void *result = allocator_alloc(ALLOCATOR(arena), 513);
	EXPECT(result == NULL);

	void *big_alloc = allocator_alloc(ALLOCATOR(arena), 512);
	EXPECT(big_alloc != NULL);
	EXPECT(arena->current_block != arena->head_block);

	deinit_arena(arena);
	return 0;
}
