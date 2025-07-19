#ifndef GPA_H
#define GPA_H

#include "allocator.h"

typedef struct {
	Allocator allocator;
} GPA;

extern GPA *init_gpa();
extern void deinit_gpa(GPA *gpa);

#endif
