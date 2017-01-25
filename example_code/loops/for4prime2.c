/*
        name:  Preetam Ghosh

        date:  Thu Jan 17 20:40:09 CST 2008

     purpose:  Determine which numbers are prime.

  pseudocode:  read n
               let i = integers from 2 to n
               for each i
                 determine if it is prime
*/

#include <stdio.h>

int main( void )
{
    int prime_stop;
    int i, j;
    int flag;  /* flag to determine what to print */

    /* prompt user for number */
    printf("Enter an integer to stop on:  ");
    scanf("%d", &prime_stop);

    printf("%3d is prime\n", 2); /* we know 2 is prime */

    for (i = 3; i <= prime_stop; i++)
    {
        flag = 0;

        /* this could actually be accomplished in the loop below,
           but it provides an opportunity to see the continue
           keyword being used 
        */
        if ((i%2) == 0)
            continue;  /* for even numbers, skip to next number */

        /* determine if i is prime.  we only need to check up to
           half the value of the number in question             */
        for (j = 3; j <= i/2; j++)
        {
            if ( (i % j) == 0 )
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            printf("%3d is prime\n", i);
    }
}

/*************************************
***             output             ***

Enter an integer to stop on:  100
  2 is prime
  3 is prime
  5 is prime
  7 is prime
 11 is prime
 13 is prime
 17 is prime
 19 is prime
 23 is prime
 29 is prime
 31 is prime
 37 is prime
 41 is prime
 43 is prime
 47 is prime
 53 is prime
 59 is prime
 61 is prime
 67 is prime
 71 is prime
 73 is prime
 79 is prime
 83 is prime
 89 is prime
 97 is prime

*************************************/
