/*
    author:  Preetam Ghosh
      date:  January 29, 2008
   purpose:  demonstrate use of logical 'and' and 'or'
*/

#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 37;
    float c = -2.8;

    if (a && b)
        printf("a && b must be true\n");

    if (b && c)
        printf("b && c must be true\n");

    if (a || b)
        printf("only one of a || b must be true\n");

    if ((a || b) && c)
        printf("(a || b) is true\n");

    if ((c || b) && a)
        printf("this fails\n");

    if ((c || b) && !a)
        printf("unless we do this\n");

    if (!(a && b) && c)
        printf("this also works\n");
}




/*************************************************
******************  Output  **********************

b && c must be true
only one of a || b must be true
(a || b) is true
unless we do this
this also works

*/
