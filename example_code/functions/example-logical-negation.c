/*
    author:  Preetam Ghosh
      date:  January 29, 2008
   purpose:  demonstrate use of logical negation
*/

#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 37;
    float c = -2.8;

    printf("a is %d, not a is %d\n", a, !a);
    printf("b is %d, not b is %d\n", b, !b);
    printf("c is %f, not c is %d\n", c, !c);

    if (!a)
        printf("I guess !a is true\n");

    if (!b)
        printf("I guess !b is true\n");

    if (!c)
        printf("I guess !c is true\n");
}

/*************************************************
******************  Output  **********************

a is 0, not a is 1
b is 37, not b is 0
c is -2.800000, not c is 0
I guess !a is true

*/

