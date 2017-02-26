#include "cmsc257-s17-assign1-support.h"
#include <stdio.h>

int i = 0;

// This function prints out the array of floating point values
int float_display_array(float floats[], int count) {
        for (i = 0; i < count; i++) {
                printf( "%.2f ", floats[i]);
        }

        printf("\n");

        return 0;
}

// This function prints out the array of integer values
int integer_display_array(int integers[], int count) {
        for (i = 0; i < count; i++) {
                printf( "%d ", integers[i]);
        }

        printf("\n");

        return 0;
}

// Return the number of even numbers in the array (float version)
int float_evens(float floats[], int count) {
        int found = 0;

        for (i = 0; i < count; i++) {
            if (!((int)floats[i] & 1)) {
                found++;
            }
        }

        return found;
}

// Return the number of even numbers in the array (int version)
int integer_evens(int integers[], int count) {
        int found = 0;

        for (i = 0; i < count; i++) {
            if (!(integers[i] & 1)) {
                    found++;
            }
        }
        return found;
}

// Count the number of '1' bits in the binary representation
int countBits(int value) {
        return 999999;
}

// Print out the values with the most occurences in array
// NOTE: this assumes values are already in order
// but because that is what `cmsc257-s17-assign1.c` comment said,
// this should be an ok assumption.
// NOTE: another assumption is that the array.size > 0,
// again, this should be fine.
int most_values(int integers[], int count) {
    int times_found = 0;
    int most_found_integer = integers[0];
    int temp_times_found = 0;

    for (i = 0; i < count; i++) {
        if (integers[i] == most_found_integer) {
            times_found++;
        } else {
            temp_times_found++;

            if (temp_times_found > times_found) {
                times_found = temp_times_found;
                temp_times_found = 0;
                most_found_integer = integers[i];
            }
        }
    }

    // TODO: verify
    return most_found_integer;
}

// Reverse the binary bit string
unsigned short reverseBits(int value) {
        return 9;
}

// Print the binary equivalent of the number passed
void binaryString(int value) {

}

// Sort the integer array using QuickSort algorithm
void integerQuickSort(int input[], int a, int b) {
    if (a < b) {
        int p = integerQuickSortPartition(input, a, b);
        integerQuickSort(input, a, p - 1);
        integerQuickSort(input, p + 1, b);
    }
}

int integerQuickSortPartition(int input[], int a, int b) {
    int p = input[b];
    int i = a - 1;
    int j = a;
    for (j = a; j < b; j++) {
        if (input[j] <= p) {
            i++;

            // SWAP
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
        }
    }

    // SWAP
    int temp = input[i + 1];
    input[i + 1] = input[b];
    input[b] = temp;

    return i + 1;
}
