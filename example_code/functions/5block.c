/*
     author:  Preetam Ghosh
       date:  February 4, 2008
    purpose:  
             1) using a loop to generate rows numbers, call a 
                function that receives only the row number which
                it uses to determine the column values to print
                out.  note that the coordinates of any particular
                value are (row, column) with (1, 1) in the upper 
                left corner
             2) do this without using arrays, any kind of lookup table, or
                just hard-coding values, i.e., don't do this
                   if (row == 1)
                     printf(" 1 2 3 4 5 6 7 8 9 10");
             3) numbers should line up
*/
#include <stdio.h>

/* function declarations */
void genline(int);


int main(void)
{
	int i;
    
    /* generate the row number */
    for(i = 1; i <=5; i++)
        genline(i);
}

/*  function definitions  */
void genline(int linenum)
{
    int i;

    /* the values produced by the for loop represent the column number.
       the mathematical function for using the column and row numbers
       to determine the value to print is 
       f(row, column) = column + 10*(row - 1)                          */
    for(i = 1; i<=10; i++)
        printf("%3d ", i + 10*(linenum - 1));

    printf("\n");
}

/*************************************************
****************   Output   **********************

  1   2   3   4   5   6   7   8   9  10
 11  12  13  14  15  16  17  18  19  20
 21  22  23  24  25  26  27  28  29  30
 31  32  33  34  35  36  37  38  39  40
 41  42  43  44  45  46  47  48  49  50

*/

