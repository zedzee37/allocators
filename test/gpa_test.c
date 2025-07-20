#include "allocator.h"
#include "test_util.h"
#include <stdio.h>
#include <gpa.h>

int main() {
	GPA *gpa = init_gpa();
	EXPECT(gpa != NULL);

	int *a = allocator_alloc(ALLOCATOR(gpa), sizeof(int));
	EXPECT(a != NULL);
	*a = 10;
	EXPECT(*a == 10);
	allocator_free(ALLOCATOR(gpa), a);

	deinit_gpa(gpa);
	return 0;
}
