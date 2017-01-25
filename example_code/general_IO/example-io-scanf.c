/*
      author:  Preetam Ghosh
        date:  Sun Mar  9 22:24:51 CDT 2008
     purpose:  Demonstrate how to use scanf()
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int int1;
    double double1;

    int int2;
    double double2;

    /* when different input values will not be separated by spaces,
       we can indicate how many characters will be in the values */
    printf("provide an int and a double\n");
    scanf("%5d%lf", &int1, &double1);
    printf("int1 is %d, double1 is %f\n", int1, double1);

    /* here we need to separate values with a space when we provide them */
    printf("\nprovide an int and a double\n");
    scanf("%d%lf", &int2, &double2);
    printf("int2 is %d, double2 is %f\n", int2, double2);
}

/*

provide an int and a double
123456789
int1 is 12345, double1 is 6789.000000

provide an int and a double
111 999
int2 is 111, double2 is 999.000000

*/

