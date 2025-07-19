#include "gpa.h"
#include "allocator.h"
#include <stdlib.h>

GPA *init_gpa() {
	GPA *gpa = malloc(sizeof(GPA));
	Allocator allocator = {
		.alloc_func = malloc,
		.free_func = free,
		.realloc_func = realloc
	};
	gpa->allocator = allocator;
	return gpa;
}

void deinit_gpa(GPA *gpa) {
	free(gpa);
}
