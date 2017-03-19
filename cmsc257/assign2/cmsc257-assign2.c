////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s17-assign1.c
//  Description    : Build Our Own Malloc
//
//   Author        : Steven Hernandez
//   Last Modified : 2017-03-06
//

// Include Files
#include <assert.h>
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
								printf("META_SIZE: %d\n", META_SIZE);

								/*
								 * Start by testing best fit
								 */
								char *a = my_malloc(sizeof(char));
								int *b = my_malloc(sizeof(int));  // will be freed, but should not be the best fit for a char
								char *c = my_malloc(sizeof(char));
								char *d = my_malloc(sizeof(char));  // will be freed, this should be best fit for a char
								char *f = my_malloc(sizeof(char));

								print_malloc_usage();
								printf("\n");

								my_free(b);
								my_free(d);

								print_malloc_usage();
								printf("\n");

								char *best_fit = my_malloc(sizeof(char));

								print_malloc_usage();
								printf("\n");

								assert(best_fit != b);
								assert(best_fit == d);

								// Trying again will have to take up b though, even though that means splitting
								char *best_fit2 = my_malloc(sizeof(char));
								assert(best_fit2 == b);

								/*
								 * Some initial variables
								 */

								char   *m_char_1;
								int    *m_int_2;
								short  *m_short_3;
								long   *m_long_4;
								float  *m_float_5;
								double *m_double_6;
								int   *m_int_7;
								int    *m_int_8;
								int    *m_int_9;
								int    *m_int_10;

								/*
								 * Allocate memory for all variables except for m_int_10
								 */
								m_char_1 = my_malloc(sizeof(char));
								m_int_2 = my_malloc(sizeof(int));
								m_short_3 = my_malloc(sizeof(short));
								m_long_4 = my_malloc(sizeof(long));
								m_float_5 = my_malloc(sizeof(float));
								m_double_6 = my_malloc(sizeof(double));
								m_int_7 = my_malloc(sizeof(int));
								m_int_8 = my_malloc(sizeof(int));
								m_int_9 = my_malloc(sizeof(int));
								// m_int_10 = my_malloc(sizeof(m_int_10));

								print_malloc_usage();
								printf("\n");

								/*
								 * Set a default value for all variables except for m_int_10
								 */
								*m_char_1 = 'c';
								*m_int_2 = 99;
								*m_short_3 = 9;
								*m_long_4 = 9999;
								*m_float_5 = 9.99;
								*m_double_6 = 9.99999999;
								*m_int_7 = m_int_2;
								*m_int_8 = 18;
								*m_int_9 = 27;
								// *m_int_10 = 36;

								my_free(m_int_8);

								// allocating another int sized block means
								// this block will be the memory previously taken up my `m_int_8`
								m_int_10 = my_malloc(sizeof(int));
								assert(*m_int_10 == 18); // m_int_8's value before being freed
								assert(m_int_8 == m_int_10); // m_int_8's value before being freed

								// // free 8 blocks
								// my_free(m_int_2);
								//
								// print_malloc_usage();
								// printf("\n");
								//
								// // we should be able to fit at least two characters in the space freed
								// // depending on our META_SIZE
								// char *m_char_11 = malloc(1);
								//
								// print_malloc_usage();
								// printf("\n");
								// char *m_char_12 = malloc(1);
								//
								// print_malloc_usage();
								// printf("\n");
								//
								// printf("These addresses SHOULD all be in order\n");
								// printf("m_char_1:        %p\n", m_char_1);
								// printf("m_char_11:       %p\n", m_char_11);
								// printf("m_char_12:       %p\n", m_char_12);
								// printf("m_short_3:       %p\n", m_short_3);
								// printf("\n");
								//
								// assert(m_char_1 < m_char_11);
								// assert(m_char_11 < m_char_12);
								// assert(m_char_12 < m_short_3);

								print_malloc_usage();
								printf("\n");

								char *c_char_1 = my_calloc(0xFF, 1);
								int *c_int_2 = my_calloc(0xFF, sizeof(int));
								char *c_char_3 = my_calloc(0x0100 - META_SIZE, 1); // calloc exactly enough so that pointers for this and the next calloc
								char *c_char_4 = my_calloc(0x0100 - META_SIZE, 1); // are 0x.........a.. and 0x.........b.. where b = a + 1
								char *c_char_5 = my_calloc(0x0100 - META_SIZE, 1);

								assert(c_char_3 + 0x0100 == c_char_4);

								my_free(c_char_1);

								print_malloc_usage();
								printf("\n");

								char *c_char_6 = my_calloc(0x0100 - META_SIZE, 1);

								print_malloc_usage();
								printf("\n");

								my_free(c_char_3);

								print_malloc_usage();
								printf("\n");

								int *c_int_7 = my_calloc(8, 8);
								int *c_int_8 = my_calloc(8, 8);
								int *c_int_9 = my_calloc(8, 8);

								print_malloc_usage();
								printf("\n");

								/*
								 * These frees should mean that blocks merge
								 */
								my_free(m_long_4);
								my_free(m_short_3);

								print_malloc_usage();
								printf("\n");

								struct block_meta *merged_blocks = get_block_ptr(m_short_3);

								assert(merged_blocks->size > sizeof(short));
								assert(merged_blocks->size == sizeof(short) + META_SIZE + sizeof(long));

								/*
								 * free reverse order, we need to check to see if we can merge with previous parent
								 */
								my_free(m_double_6);
								my_free(m_int_7);

								struct block_meta *merged_blocks2 = get_block_ptr(m_double_6);
								print_malloc_usage();
								printf("\n");

								assert(merged_blocks2->size == sizeof(double) + META_SIZE + sizeof(int));

								/*
								 * all 5 of these elements should merge now (at this point it should just be 3 elements)
								 */
								my_free(m_float_5);

								struct block_meta *merged_blocks3 = get_block_ptr(m_short_3);

								assert(merged_blocks3->size == (META_SIZE * 4) + sizeof(short) + sizeof(long) + sizeof(float) + sizeof(double) + sizeof(float));

								// because of these `free` calls, this should not have to malloc new memory
								int *c_int_10 = my_calloc(2, 8);

								assert(c_int_10 < c_int_9);

								print_malloc_usage();
								printf("\n");

								char *c_char_11 = my_calloc(0x0100 - META_SIZE, 1);
								char *c_char_12 = my_calloc(0x0100 - META_SIZE, 1);
								char *c_char_13 = my_calloc(0x0100 - META_SIZE, 1);

								print_malloc_usage();
								printf("\n");

								// halve the size of these
								char *r_char_1 = my_realloc(c_char_11, 0x50 - META_SIZE * 1);
								char *r_char_2 = my_realloc(c_char_12, 0x50 - META_SIZE * 1);
								char *r_char_3 = my_realloc(c_char_13, 0x50 - META_SIZE * 1);

								print_malloc_usage();
								printf("\n");

								assert(r_char_1 == c_char_11);
								assert(r_char_2 == c_char_12);
								assert(r_char_3 == c_char_13);

								// shrink size again
								char *r_char_4 = my_realloc(r_char_1, 0x30 - META_SIZE * 1);
								char *r_char_5 = my_realloc(r_char_2, 0x30 - META_SIZE * 1);
								char *r_char_6 = my_realloc(r_char_3, 0x30 - META_SIZE * 1);

								print_malloc_usage();
								printf("\n");

								assert(r_char_4 == c_char_11);
								assert(r_char_5 == c_char_12);
								assert(r_char_6 == c_char_13);

								// increase size
								char *r_char_7 = my_realloc(r_char_4, 0x200 - META_SIZE * 1); // larger than original block, thus must be malloc-ed again
								char *r_char_8 = my_realloc(r_char_5, 0x90 - META_SIZE * 1);
								char *r_char_9 = my_realloc(r_char_6, 0x60 - META_SIZE * 1);

								print_malloc_usage();
								printf("\n");

								// assert(r_char_7 != c_char_11);
								// assert(r_char_7 > c_char_11); // because this realloc is larger than the space available
								// assert(r_char_8 == c_char_12);
								// assert(r_char_9 == c_char_13);

								// // this didn't successfully realloc last time, so we can retry without effecting r_char_7
								// char *r_char_10 = my_realloc(r_char_4, 0x60 - META_SIZE * 1);
								//
								// print_malloc_usage();
								// printf("\n");
								//
								// assert(r_char_10 == c_char_11);
								//
								// /*
								//  * attempt splitting
								//  */
								// print_malloc_usage();
								// printf("\n");
								//
								// int *m = my_calloc(2000, sizeof(int));
								// int *n = my_calloc(2000, sizeof(int));
								// int *o = my_calloc(2000, sizeof(int));
								//
								// my_free(n);
								//
								// int *split1 = my_calloc(200, sizeof(int));
								// int *split2 = my_calloc(200, sizeof(int));
								//
								// print_malloc_usage();
								// printf("\n");
								//
								// assert(m < split1);
								// assert(split1 < split2);
								// assert(split2 < o);
}


/*
   m_char_1
   m_int_2
   m_short_3
   m_long_4
   m_float_5
   m_double_6
   m_int_7
   m_int_8
   m_int_9
   m_int_10
 */
