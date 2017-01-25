/*
     author:  Preetam Ghosh,

       date:  February 1, 2008

    purpose:  Determine the memory requirements for different types of ints.  
              Also, demonstrate what happens when an int is incremented beyond
	      its size.
*/

#include <stdio.h>
#include <math.h>

/*     function declarations      */
long int maxNum(int);


int main(void)
{
    short int smallnum;
    int mediumnum;
    long int bignum;
    int i;

    /* determine number of bytes used for each type */
    printf("the size of a short int is %d\n", sizeof(smallnum));
    printf("the size of an int is %d\n", sizeof(mediumnum));
    printf("the size of a long int is %d\n", sizeof(bignum));

    /* determine maximum representable value */
    smallnum = maxNum(sizeof(smallnum));
    printf("\nthe maximum value of smallnum is %d\n", smallnum);
    
    mediumnum = maxNum(sizeof(mediumnum));
    printf("the maximum value of mediumnum is %d\n", mediumnum);
    
    bignum = maxNum(sizeof(bignum));
    printf("the maximum value of bignum is %ld\n\n", bignum);

    /* push each number until it exceeds the space allocated */
    for (i = 1; i <=5; i++)\
    {
        printf("smallnum is %6d, ", smallnum);
        printf("mediumnum is %11d, ", mediumnum);
        printf("bignum is %20ld\n", bignum);
        smallnum++;
        mediumnum++;
        bignum++;
    }
}

/*     function definitions       */

/*  function:  maxNum
    purpose:  determine the maximum size of a signed integer
    input:  number of bytes
    output:  maximum representable number in base 10
*/
long int maxNum(int num)
{
    long int maxvalue;
    double base = 2;
    double exponent = num*8 - 1;

    maxvalue = (long int)(pow(base, exponent)) - 1;

    return maxvalue; 
}

/******************************************************************
**********           Output on a 64-bit machine          **********
**********   this could be different on other hardware   **********

the size of a short int is 2
the size of an int is 4
the size of a long int is 8

the maximum value of smallnum is 32767
the maximum value of mediumnum is 2147483647
the maximum value of bignum is 9223372036854775807

smallnum is  32767, mediumnum is  2147483647, bignum is  9223372036854775807
smallnum is -32768, mediumnum is -2147483648, bignum is -9223372036854775808
smallnum is -32767, mediumnum is -2147483647, bignum is -9223372036854775807
smallnum is -32766, mediumnum is -2147483646, bignum is -9223372036854775806
smallnum is -32765, mediumnum is -2147483645, bignum is -9223372036854775805

*/
