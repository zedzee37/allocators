#ifndef	TEST_UTIL_H
#define TEST_UTIL_H

#define EXPECT(b) \
	 if (b) { \
    	printf("\033[32mCheck %s succeeded!\033[0m\n", #b); \
	} else { \
		printf("\033[0;31mCheck %s failed!\033[0m\n", #b); \
	   return 1; \
	 } \

#endif
