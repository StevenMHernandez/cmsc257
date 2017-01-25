/*
     author:  Preetam Ghosh
       date:  June 22, 2008
    purpose:  Generate months at random, without repeating.
*/

#include <stdio.h>
#include <time.h>

enum bln {F, T};

int getMonth(short *);

int main(void)
{
    int i;
    char *months[] = {"January", "February", "March", "April", 
                      "May", "June", "July", "August", 
                      "September", "October", "November", "December"};
    short month_bits = 0;
    int month_num;

    srand( (unsigned) time(NULL) );

    while( month_bits != 4095 ) /* has all 12 months */
    {
        month_num = getMonth( &month_bits );

        printf("%s\n", months[month_num]);
    }

}


int getMonth(short *bits)
{
    /*  bits is an integer for storing which months have been used
        It initially has a value of zero, which has a bit pattern
        of all zeros.  A random number from 0 to 11 is generated,
        representing a potential month.  To determine if this month
        has been used before, it is first used to produce a bit
        pattern in which there is a 1 in the column for that month.
        For example, if the number generated is 2, then

            1 << 2 

        produces

            0000000000000100

        By using bitwise and, this number can be compared to the
        existing bit pattern to determine if there is already a 1
        in this month's column.  If this month has not been used,
        then this bit pattern is used with a bitwise or to change
        the bit pattern representing months seen.
    */
    int random_month;
    enum bln unseen_month = F;
    short random_month_bits;

    while (unseen_month == F)
    {
        random_month = rand() % 12;  /*choose random month*/
        random_month_bits = 1 << random_month;
        if( (*bits & random_month_bits) == 0)
            unseen_month = T;   /* we haven't seen 
                                   this month before */
    }

    *bits = *bits | random_month_bits;  /* update month bit pattern */

    return random_month;
}

/*******************************************
***               Output                 ***

$ ./months-bits 
February
December
August
November
January
July
April
May
October
March
June
September

$ ./months-bits 
September
July
March
December
November
August
April
February
October
May
June
January

*/
