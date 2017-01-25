/*
    Preetam Ghosh
    January 30, 2008
    print out the first 12 values of a Fibonacci sequence
*/
#include <stdio.h>

int main(void)
{
    int x_previous = 0; /* the first value in the sequence  */
    int x_current = 1;  /* the second value in the sequence */
    int x_next;         /* the calculated next value in the sequence   */
    int i;

    printf("%d, %d", x_previous, x_current);  /* this prints the first two 
                                                 numbers in the sequence */

    /* calculate the next 10 values of the sequence */
    for(i = 1; i <=10; i++)
    {
        /* to generate the next number in a Fibonacci sequence, sum the two
           most recent numbers
        */
        x_next = x_current + x_previous;
        printf(", %d", x_next);
        
        /* update the variables representing the two most
           recent values of the sequence in anticipation of
           calculating the next value of the sequence       */
        x_previous = x_current;
        x_current = x_next;
    }

    /* print a newline so that the line cursor doesn't end up
       on the same line as the sequence */
    printf("\n");
}


/************************************************
**************    Output    *********************

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89

*/
