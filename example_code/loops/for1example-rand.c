/*
    problem:  We want to simulate rolling a 6-sided die.  We know that 
    the Standard C Library has a rand() function.  The range of values
    produced by rand() can vary depending on the compiler, but they 
    should at least include the range of 0 to 32767.  How do we get 
    values from 1 to 6?

    pseudocode: get random number
                random_number mod 6 will produce values from 0 to 5,
		          so add 1 to result

    NOTE: Because we don't seed rand(), this program will always
          generate the same `random' values.
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int i;
    int randval;

    for( i = 0; i < 10; i++ )
    {
        randval = rand();
        printf( "Original random number is %6d; die roll value is %d\n", 
            randval, (randval%6 + 1) );   
    }
}

/**************************************************************
*********************   Output   ******************************

Original random number is     41; die roll value is 6
Original random number is  18467; die roll value is 6
Original random number is   6334; die roll value is 5
Original random number is  26500; die roll value is 5
Original random number is  19169; die roll value is 6
Original random number is  15724; die roll value is 5
Original random number is  11478; die roll value is 1
Original random number is  29358; die roll value is 1
Original random number is  26962; die roll value is 5
Original random number is  24464; die roll value is 3

*/

