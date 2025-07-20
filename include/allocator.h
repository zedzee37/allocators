#ifndef ALLOCATORS_H
#define ALLOCATORS_H

#include <stddef.h>

#define ALLOCATOR(alloc) (Allocator *)alloc

typedef struct Allocator Allocator;

typedef void *(*AllocFunc)(Allocator *allocator, size_t size);
typedef void (*FreeFunc)(Allocator *allocator, void *addr);
typedef void *(*ReallocFunc)(Allocator *allocator, void *addr, size_t new_size);

typedef struct Allocator {
	AllocFunc alloc_func;
	FreeFunc free_func;
	ReallocFunc realloc_func;
} Allocator;

extern void *allocator_alloc(Allocator *allocator, size_t size);
extern void allocator_free(Allocator *allocator, void *addr);
extern void *allocator_realloc(Allocator *allocator, void *addr, size_t new_size);

#endif
