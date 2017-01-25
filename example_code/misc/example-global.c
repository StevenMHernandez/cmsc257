#include <stdio.h>

int x = 5;

void changeX(void);

int main(void)
{
    printf("x is %d\n", x);
    changeX();
    printf("x is %d\n", x);
}

void changeX(void)
{
    printf("x is %d\n", x);
    x += 3;
}

/**********************************************
***                 Output                  ***

x is 5
x is 5
x is 8

*/
