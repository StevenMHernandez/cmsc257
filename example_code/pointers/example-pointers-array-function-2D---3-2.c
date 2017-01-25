#include <stdio.h>

int sum1(int (*a)[5], int);
int sum2(int a[][5], int);

int main(void)
{
    int sales[][5] = { {40, 35, 30, 25, 20},
                       {20, 30, 40, 50, 60},
                       {45, 55, 65, 75, 85},
                       {30, 35, 40, 45, 50} };

    int rows, cols, sum;

    cols = sizeof(sales[0])/sizeof(int);
    rows = (sizeof(sales)/cols)/sizeof(int);

    sum = sum1(sales, rows);
    printf("the sum is %d\n", sum);

    sum = sum2(sales, rows);
    printf("the sum is still %d\n", sum);
}

int sum1(int (*a)[5], int rows)
{
    int i, k;
    int sum = 0;

    for(i = 0; i < rows; i++)
        for(k = 0; k < 5; k++)
            sum += *(*(a + i) + k);

    return sum;
}

int sum2(int a[][5], int rows)
{
    int i, k;
    int sum = 0;

    for(i = 0; i < rows; i++)
        for(k = 0; k < 5; k++)
            sum += a[i][k];

    return sum;
}

/***************************
***       Output         ***

the sum is 875
the sum is still 875

*/
