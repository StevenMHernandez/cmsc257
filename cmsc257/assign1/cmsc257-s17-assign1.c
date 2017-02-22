////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s17-assign1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMSC257.  See the related
//                   assignment page for details.
//
//   Author        : ????
//   Last Modified : ????
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
    int i, m_array[25];
    ????

	// Step #1 - read in the float numbers to process
	for (i=0; i<20; i++) {
		scanf("%f", &f_array[i]);
	}

    // Step #2 - convert the floating point values to integers
    ????

    // Step #3 - print out the integer and floating point arrays
    ????
    
    // Step #4 - print out the number of '1's in each integer
    ???? 

    // Step #5 - Sort the integer array using QuickSort and print the sorted array
    ????

    // Step #6 - figure out number of evens in each array (float and sorted integer arrays)
    ????

    // Step #7 - print the most frequent values from the sorted integer array
    ???? 

    // Step #8 - print the integers corresponding to the reverse bit string from integer array
    ????

	// Return successfully
	return(0);
}
