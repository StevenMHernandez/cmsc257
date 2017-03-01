#ifndef CMSC257_A1SUPPORT_INCLUDED
#define CMSC257_A1SUPPORT_INCLUDED

////////////////////////////////////////////////////////////////////////////////
//
//  File          : cmsc257-s17-assign1-support.h
//  Description   : This is a set of general-purpose utility functions we use
//                  for the 257 assignment #1.
//
//  Author   : Steven Hernandez
//  Created  : 2017-02-22

//
// Functional Prototypes

int float_display_array(float floats[], int count);
	// This function prints out the array of floating point values

int integer_display_array(int integers[], int count);
	// This function prints out the array of integer values

int float_evens(float floats[], int count);
	// Return the number of even numbers in the array (float version)

int integer_evens(int integers[], int count);
	// Return the number of even numbers in the array (int version)

int countBits(int value);
	// Count the number of '1' bits in the binary representation

int most_values(int integers[], int count);
	// Print out the values with the most occurences in array

unsigned short reverseBits(unsigned short value);
        // Reverse the binary bit string

void binaryString(int value);
        // Print the binary equivalent of the number passed

void integerQuickSort(int input[], int a, int b);
        // Sort the integer array using QuickSort algorithm

int integerQuickSortPartition(int input[], int a, int b);

#endif // CMSC257_A1SUPPORT_INCLUDED
