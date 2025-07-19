#include <allocator.h>

void *allocator_alloc(Allocator *allocator, size_t size) {
	return allocator->alloc_func(size);
}

void allocator_free(Allocator *allocator, void *addr) {
	allocator->free_func(addr);
}

void *allocator_realloc(Allocator *allocator, void *addr, size_t new_size) {
	return allocator->realloc_func(addr, new_size);
}
