////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s17-assign1.c
//  Description    : Build Our Own Malloc
//
//   Author        : Steven Hernandez
//   Last Modified : 2017-03-06
//

// Include Files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Project Includes
#include "malloc.h"

////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CMSC257 assignment #2
//
// Outputs      : 0 if successful test, -1 if failure
int main(int argc, char *argv[]) {
	int *example1;
	int *example2;
	int *example3;
	int *example4;

	example1 = my_malloc(8);
	example2 = my_malloc(8);
	example3 = my_malloc(8);
	example4 = my_malloc(8);

	printf("%p: %p: %d\n", &example1, example1, *example1);
	printf("%p: %p: %d\n", &example2, example2, *example2);
	printf("%p: %p: %d\n", &example3, example3, *example3);
	printf("%p: %p: %d\n", &example4, example4, *example4);

	*example1 = 3;
	*example2 = 9;
	*example3 = 18;
	*example4 = 27;

	my_free(example1);

	example4 = my_malloc(8);

	*example4 = 99;

	printf("%p: %p: %d\n", &example1, example1, *example1);
	printf("%p: %p: %d\n", &example2, example2, *example2);
	printf("%p: %p: %d\n", &example3, example3, *example3);
	printf("%p: %p: %d\n", &example4, example4, *example4);

	my_free(example2);

	print_malloc_usage();
}


