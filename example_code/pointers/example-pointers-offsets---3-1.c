#include <stdio.h>

int main(void)
{
    int num[][3] = { {25, 26, 27},
                     {28, 29, 30},
                     {31, 32, 33},
                     {34, 35, 36} };
    int i, j;

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 3; j++)
            printf("%d %p    ", num[i][j], &num[i][j]);

        printf("\n");
    }

    printf("\n");
    printf("*num              %p\n", *num );
    printf("*(num + 1)        %p\n", *(num + 1) );
    printf("*(num + 2)        %p\n", *(num + 2) );
    printf("*((num + 1) + 2)  %p\n", *((num + 1) + 2) );
    printf("*((num + 2) + 1)  %p\n", *((num + 2) + 1) );
    printf("*(num + 3)        %p\n", *(num + 3) );
    printf("*num + 1          %p\n", *num + 1 );
    printf("*num + 2          %p\n", *num + 2 );
    printf("\n");
    printf("*(num + 1) + 2    %p\n", *(num + 1) + 2 );
    printf("*(num + 2) + 1    %p\n", *(num + 2) + 1 );
    printf("\n");
    printf("*(*(num + 1) + 2) is %d\n", *(*(num + 1) + 2) );
    printf("*(*(num + 2) + 1) is %d\n", *(*(num + 2) + 1) );
}

/********************************************************
****             Output (with comments)              ****

25 0012FF50    26 0012FF54    27 0012FF58
28 0012FF5C    29 0012FF60    30 0012FF64
31 0012FF68    32 0012FF6C    33 0012FF70
34 0012FF74    35 0012FF78    36 0012FF7C

*num              0012FF50   <== address of array (row 0)
*(num + 1)        0012FF5C   <== address of row 1
*(num + 2)        0012FF68   <== address of row 2
*((num + 1) + 2)  0012FF74   <== address of row 3
*((num + 2) + 1)  0012FF74   <== address of row 3
*(num + 3)        0012FF74   <== address of row 3
*num + 1          0012FF54   <== address of row 0, column 1
*num + 2          0012FF58   <== address of row 0, column 2

*(num + 1) + 2    0012FF64   <== address of row 1, column 2
*(num + 2) + 1    0012FF6C   <== address of row 2, column 1

*(*(num + 1) + 2) is 30      <== element at row 1, column 2
*(*(num + 2) + 1) is 32      <== element at row 2, column 1


*/

