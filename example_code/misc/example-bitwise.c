/*
    demonstrate use of bitwise operations
*/

#include<stdio.h>

int main(void)
{
    /*
        Each number here is shown as if it only occupies 
        8 bits with the high bit being the sign bit.

        0 = 00000000
        1 = 00000001
        2 = 00000010
        3 = 00000011
        4 = 00000100
        5 = 00000101
        6 = 00000110
        7 = 00000111

       -7 = 11111001
       -6 = 11111010
       -5 = 11111011
       -4 = 11111100
       -3 = 11111101
       -2 = 11111110
       -1 = 11111111
    */

    int a = 2;
    short x = 20000;
    short z;

    /*  bitwise-negation  */
    printf("~3 is %d\n", ~3);       /* ~3 is 11111100 */
    printf("~4 is %d\n", ~4);       /* ~4 is 11111011 */
    printf("~5 is %d\n\n", ~5);     /* ~5 is 11111010 */

    /*  bitwise-and       */
    printf("3 & 4 is %d\n", 3 & 4);   /* 3 & 4 is 00000000 */
    printf("3 & 5 is %d\n", 3 & 5);   /* 3 & 5 is 00000001 */
    printf("4 & 5 is %d\n\n", 4 & 5); /* 4 & 5 is 00000100 */

    /*  bitwise-or        */
    printf("3 | 4 is %d\n", 3 | 4);   /* 3 | 4 is 00000111 */
    printf("3 | 5 is %d\n", 3 | 5);   /* 3 | 5 is 00000111 */
    printf("4 | 5 is %d\n\n", 4 | 5); /* 4 | 5 is 00000101 */

    /*  bitwise-xor       */
    printf("3 ^ 4 is %d\n", 3 ^ 4);   /* 3 ^ 4 is 00000111 */
    printf("3 ^ 5 is %d\n", 3 ^ 5);   /* 3 ^ 5 is 00000110 */
    printf("4 ^ 5 is %d\n\n", 4 ^ 5); /* 4 ^ 5 is 00000001 */

    /*  shift left        */
    z = x << 1;
    printf("%d shifted left once is %d\n", x, z);
    printf("%d shifted left once is %d\n", a, a << 1);
    printf("%d shifted left twice is %d\n", a, a << 2);
    printf("%d shifted left three times is %d\n", a, a << 3);
    printf("%d shifted left twenty times is %d\n\n", a, a << 20);

    /*  shift right       */
    z = x >> 1;
    printf("%d shifted right once is %d\n", x, z);
}

/*********************************************************
********               Output                      *******

~3 is -4
~4 is -5
~5 is -6

3 & 4 is 0
3 & 5 is 1
4 & 5 is 4

3 | 4 is 7
3 | 5 is 7
4 | 5 is 5

3 ^ 4 is 7
3 ^ 5 is 6
4 ^ 5 is 1

20000 shifted left once is -25536
2 shifted left once is 4
2 shifted left twice is 8
2 shifted left three times is 16
2 shifted left twenty times is 2097152

20000 shifted right once is 10000

*/
