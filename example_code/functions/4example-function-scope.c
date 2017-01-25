/*
    Preetam Ghosh
    Wed Jan 30 09:54:53 CST 2008
    Demonstrate scope in functions
*/

#include <stdio.h>

/*     function declarations */
void dosomething(int);

int main(void)
{
    int i = 4, x = 15;

    dosomething(x);
    printf("i is %d, x is %d\n", i, x);
}


/*     function definition   */
void dosomething(int x)
{
    int i  = 768;
    x = x + x;
    printf("in here, i is %d, x is %d\n", i, x);
}













/*************   Output ***********************

in here, i is 768, x is 30
i is 4, x is 15

*/
