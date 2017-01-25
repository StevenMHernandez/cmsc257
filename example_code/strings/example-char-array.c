/*
     author:  Preetam Ghosh,

       date:  February 6, 2008

    purpose:  demonstrate use of char
*/

#include <stdio.h>

int main(void)
{
    char firstname[7];
    char lastname[] = {'G', 'h', 'o', 's', 'h'};
    int i;

    firstname[0] = 'P';
    firstname[1] = 'r';
    firstname[2] = 'e';
    firstname[3] = 'e';
    firstname[4] = 't';
    firstname[5] = 'a';
    firstname[6] = 'm';

    for(i = 0; i < 7; i++) 
        printf("%c", firstname[i]);

    printf(" "); /* put a space between the names */

    for(i = 0; i < 5; i++) 
        printf("%c", lastname[i]);

    printf("\n"); /* add a newline so that the cursor doesn't end up 
                     at the end of the line with the name            */
}

/**********************************************************
******************    Output    ***************************

Preetam Ghosh

*/
