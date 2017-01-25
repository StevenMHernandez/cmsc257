/*
       name:  Preetam Ghosh

       date:  March 12, 2008

    purpose:  demonstrate the use of the Standard C library
*/

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    char texti[] = "1234";
    char textd[] = "10.893";
    int numi;
    double numd;

    numi = atoi(texti);
    printf("%d\n", numi + 6);

    numd = atof(textd);
    printf("%f\n", numd);
}


/****************************************************************

1240
10.893000

*/
