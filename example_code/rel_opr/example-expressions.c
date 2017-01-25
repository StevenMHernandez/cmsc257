/*
    Demonstrate the values produced by various comparisons.

    September 16, 2008
*/
#include <stdio.h>

int main(void)
{
    int x = 0;
    printf("           x == 5 is %d\n", x == 5);
    printf("            x = 5 is %d\n", x = 5);
    printf("           x == 5 is %d\n", x == 5);
    printf("     99 > (x = 4) is %d\n", 99 > (x = 4) );
    printf("                x is %d\n", x);

    printf("          22 < 33 is %d\n", 22 < 33);
    printf("          22 > 33 is %d\n", 22 > 33);
    printf("     22 < 44 < 33 is %d\n", 22 < 44 < 33);
    printf("     22 > 44 < 33 is %d\n", 22 > 44 < 33);
    printf("     22 < 33 < 44 is %d\n", 22 < 33 < 44);
    printf("       0.25 < 0.5 is %d\n", 0.25 < 0.5);
    printf("0.25 < 0.5 < 0.75 is %d\n", 0.25 < 0.5 < 0.75);
}











/*

           x == 5 is 0
            x = 5 is 5
           x == 5 is 1
     99 > (x = 4) is 1
                x is 4
          22 < 33 is 1
          22 > 33 is 0
     22 < 44 < 33 is 1
     22 > 44 < 33 is 1
     22 < 33 < 44 is 1
       0.25 < 0.5 is 1
0.25 < 0.5 < 0.75 is 0

*/

