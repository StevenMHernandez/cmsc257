#include <stdio.h>

int swapplus(int*, int*); 

int main(void)
{
    int x = 8;
    int y = 14;
    int sum;

    sum = swapplus(&x, &y);

    printf("x is %d, y is %d, and x + y is %d\n", x, y, sum);
}

/* this function returns a value to demonstrate that we 
   can still do this even if using pointers
*/
int swapplus(int* aptr, int* bptr)
{
    int temp;

    temp = *aptr;
    *aptr = *bptr;
    *bptr = temp;
    
    return *aptr + *bptr;
}


/*********************************************************
***********               Output               ***********

x is 14, y is 8, and x + y is 22

*/
