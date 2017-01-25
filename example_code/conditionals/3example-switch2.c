/*
    Preetam Ghosh
    May 24, 2008

    Comparison of if-else and switch structures.
*/

#include <stdio.h>

int main(void)
{
    int x = 3;

    if(x == 1)
    {
        printf("x is 1\n");
    }
    else if(x == 2)
    {
        printf("x is 2\n");
    }
    else if(x == 3)
    {
        printf("x is 3\n");
    }
    else if(x == 4)
    {
        printf("x is 4\n");
    }
    else if(x == 5)
    {
        printf("x is 5\n");
    }

    switch(x)
    {
        case 1: printf("now x is 1\n"); break;
        case 2: printf("now x is 2\n"); break;
        case 3: printf("now x is 3\n"); break;
        case 4: printf("now x is 4\n"); break;
        case 5: printf("now x is 5\n"); break;
    }
}

/******************************
***          Output         ***

x is 3
now x is 3

*/
