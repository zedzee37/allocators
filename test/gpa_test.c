#include "allocator.h"
#include "test_util.h"
#include <stdio.h>
#include <gpa.h>

int main() {
	GPA *gpa = init_gpa();
	EXPECT(gpa != NULL);

	int *a = allocator_alloc(&gpa->allocator, sizeof(int));
	EXPECT(a != NULL);
	*a = 10;
	EXPECT(*a == 10);
	allocator_free(&gpa->allocator, a);

	deinit_gpa(gpa);
	return 0;
}
