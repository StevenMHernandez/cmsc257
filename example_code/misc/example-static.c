#include <stdio.h>

int fct(void)
{
    int a = 0; 
          
    a++;
    return a;
}

int fctstatic(void)
{
    static int b;  /* static variables can be initialized like
                      automatic variables; otherwise they are 
                      automatically initialized to 0         */
    b++;
    return b;
}

int main(void)
{
    int x, y;
    int i;

    for(i = 0; i < 3; i++)
    {
        x = fct();
        y = fctstatic();
        printf("x is %d, y is %d\n", x, y);
    }
}

/*************************************
***            Output              ***

x is 1, y is 1
x is 1, y is 2
x is 1, y is 3

*/
