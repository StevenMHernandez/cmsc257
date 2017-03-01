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
                // if the final bit is 1, then it is odd, so we only count ints that are not odd
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
                // if the final bit is 1, then it is odd, so we only count ints that are not odd
                if (!(integers[i] & 1)) {
                        found++;
                }
        }
        return found;
}

// Count the number of '1' bits in the binary representation
int countBits(int value) {
        int count = 0;
        int compare = 1; // start with b00000001

        do {
                if (value & compare) { // check if the bit is on in value
                        count++;
                }
                compare = compare << 1; // shift `compare` over on to check the next bit
        } while (compare);

        return count;
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
                        times_found++; // if this new integer is the same as our previously though `most_found_integer`, then increment count
                } else {
                        temp_times_found++; // if different, then it may mean that this new value is the real `most_found_integer`

                        if (temp_times_found > times_found) { // if we found this new value more often, then the previous most found integer, then this value becomes the new most found integer
                                times_found = temp_times_found;
                                temp_times_found = 0;
                                most_found_integer = integers[i];
                        }
                }
        }

        return most_found_integer;
}

// Reverse the binary bit string
unsigned short reverseBits(unsigned short value) {
        unsigned short temp = 0;
        int compare = 1 << sizeof(int); // := b1000...000
        int placement = 1;          // := b0000...001
        int inv = ~0;

        do {
                // if the bit at b000..1..
                // then we get b1111...1 if not, b0000...0
                // which is then `&` with the mirrored location in our bit sequence
                // which we finally `|` with temp to keep our previous values.
                temp = temp | (placement & (value & compare ? inv : 0));

                placement = placement << 1; // shift the bit in placement one left
                compare = compare >> 1; // shift the bit in compare one right
        } while (compare);

        return temp;
}

// Print the binary equivalent of the number passed
void binaryString(int value) {
        int compare = 1 << sizeof(int); // := b1000...000

        do {
                // print 1 or zero if bit at location is `1`
                printf("%i", value & compare ? 1 : 0);
                // shift compare bit right
                compare = compare >> 1;
        } while (compare);

        printf(" ");
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
