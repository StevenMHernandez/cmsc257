/*
    author:  Preetam Ghosh

      date:  January 22, 2008

   purpose:  Determine if a year is a leapyear.

             How do we know if a year is a leap year?
             If a year is not evenly divisible by 4, then it
             is not a leap year.  If it is evenly divisible 
             by 4, there are two additional considerations.  
             If the year is evenly divisible by  4 but not 
             evenly divisible by 100, then it is a leap year.
             If the year is evenly divisible by 100, then it 
             must also be evenly divisible by 400 to be a leap 
             year.  For example, the years 2008 and 2000 are 
             leap years but 1900 is not.

     NOTES:  The #define statement is necessary to turn off Visual Studio's
             warnings for using scanf().

             Here is a solution based on an example in The C 
             Programming Language, 2nd Ed., by Kernighan and 
             Ritchie.  Note that it uses logical `and' and 
             `or' to represent the conditions for determining 
             a leap year.  In doing so, all of the conditions 
             can be represented in a single expression.

        if( year%4 == 0 && year%100 != 0 || year%400 == 0 )
            printf("%d is a leap year\n", year);
        else
            printf("%d is not a leap year\n", year);
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main( void )
{
    int year;

    printf("Enter a year:  ");
    scanf("%d", &year); 

    if ((year%4) == 0)
        if ((year%100) == 0)
            if ((year%400) == 0)
                printf("%d is a leap year\n", year);
            else
                printf("%d is not a leap year\n", year);
        else
            printf("%d is a leap year\n", year);
    else
        printf("%d is not a leap year\n", year);
}

