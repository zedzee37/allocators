#include "gpa.h"
#include "allocator.h"
#include <stddef.h>
#include <stdlib.h>

void *gpa_malloc(Allocator *allocator, size_t size) {
	return malloc(size);
}

void gpa_free(Allocator *allocator, void *addr) {
	free(addr);
}

void *gpa_realloc(Allocator *allocator, void *addr, size_t new_size) {
	return realloc(addr, new_size);
}

GPA *init_gpa() {
	GPA *gpa = malloc(sizeof(GPA));
	Allocator allocator = {
		.alloc_func = gpa_malloc,
		.free_func = gpa_free,
		.realloc_func = gpa_realloc
	};
	gpa->allocator = allocator;
	return gpa;
}

void deinit_gpa(GPA *gpa) {
	free(gpa);
}
