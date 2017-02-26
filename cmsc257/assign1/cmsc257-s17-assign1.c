////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s17-assign1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMSC257.  See the related
//                   assignment page for details.
//
//   Author        : Steven Hernandez
//   Last Modified : 2017-02-22
//

// Include Files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Project Includes
#include <cmsc257-s17-assign1-support.h>

//
// Functions

////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CMSC257 assignment #1
//
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure

int main(int argc, char *argv[]) {

	// Local variables
	// NOTE: this is where you will want to add some new variables
	float f_array[20];
    int i, m_array[20];

	// Step #1 - read in the float numbers to process
	for (i=0; i<20; i++) {
		scanf("%f", &f_array[i]);
	}

    // Step #2 - convert the floating point values to integers
    for (i=0; i<20; i++) {
        m_array[i] = (int)f_array[i];
    }

    // Step #3 - print out the integer and floating point arrays
    float_display_array(f_array, 20);
    integer_display_array(m_array, 20);

    // Step #4 - print out the number of '1's in each integer
    for (i=0; i<20; i++) {
        printf("%d ", countBits(m_array[i]));
    }

    printf("\n");

    // Step #5 - Sort the integer array using QuickSort and print the sorted array
	integerQuickSort(m_array, 0, 19);
	integer_display_array(m_array, 20);

    // Step #6 - figure out number of evens in each array (float and sorted integer arrays)
    printf("%d\n", float_evens(f_array, 20));
    printf("%d\n", integer_evens(m_array, 20));

    // Step #7 - print the most frequent values from the sorted integer array
    printf("%d\n", most_values(m_array, 20));

    // Step #8 - print the integers corresponding to the reverse bit string from integer array
    for (i=0; i<20; i++) {
        printf("%d, ", reverseBits(m_array[i]));
    }

    printf("\n");

	// Return successfully
	return(0);
}
