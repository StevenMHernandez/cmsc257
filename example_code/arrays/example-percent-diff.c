/*
    pseudocode:  Since I will be comparing adjacent values,
                 this would probably be a good use for an array
                 because I can do this by changing the subscripts.
                 Also, the large quantity of values will be easier
                 to manage in an array.

                 The percent change in going from value x[i] to 
                 x[i + 1] is ((x[i + 1] - x[i])/x[i]) * 100.

                 If there are n values, we should loop from the first
                 value to n-1, calculating the percent change for each 
                 adjacent pair.  There will be n-1 comparisons.
*/

#include <stdio.h>

int main (void)
{
    int i;
    int data[] = {8, 9, 13, 7, 14, 11, 11, 15, 2};
    float change;

    int numvalues = sizeof(data)/sizeof(int);
    /*
    printf("numvalues is %d\n", numvalues);
    */

    for(i = 0; i < numvalues-1; i++)
    {
        change = (( (float)data[i + 1] - data[i])/data[i]) * 100;
        printf("The percent change from %2d to %2d is %6.2f%%\n", 
                data[i], data[i+1], change);
    }
}

/*************************************************************
*************************   Output   *************************
The percent change from  8 to  9 is  12.50%
The percent change from  9 to 13 is  44.44%
The percent change from 13 to  7 is -46.15%
The percent change from  7 to 14 is 100.00%
The percent change from 14 to 11 is -21.43%
The percent change from 11 to 11 is   0.00%
The percent change from 11 to 15 is  36.36%
The percent change from 15 to  2 is -86.67%

*/
