/*
    author:  Preetam Ghosh

      date:  Wed Jan 30 10:34:51 CST 2008

   purpose:  Demonstrate a variety of ways of using a function.
*/

#include <stdio.h>

/*   function declaration   */
int addnums(int, int);

int main(void)
{
    int x = 3, y = 4, w, z;
   
    z = addnums(x, 9);
    w = 10 + addnums(x, y);
    printf("z is %d, w is %d\n", z, w);

    printf("x = %d, so x + x is %d\n", x, addnums(x,x));

    if (addnums(2, 3) == 5)
        printf("we can use functions here also\n");
}

/*   function definition   */
int addnums(int a, int b)
{
    return a + b;
}







/****************************************************************
******************        Output      ***************************

z is 12, w is 17
x = 3, so x + x is 6
we can use functions here also

*/
