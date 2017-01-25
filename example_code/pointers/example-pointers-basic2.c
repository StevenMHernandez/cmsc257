#include <stdio.h>

int main(void)
{
    int num = 3;  /* num has a variable type of int       */
    int val = 5;
    int* numptr;  /* numptr has a variable type of int *  */
    int* valptr;

    printf("num is %d, val is %d\n", num, val);

    numptr = &num;
    valptr = &val;

    printf("  numptr is %p\n  valptr is %p\n", numptr, valptr);

    val = 3;
    if(*numptr == *valptr)
    {
        printf("\nnow num is %d, val is %d\n", num, val);
        printf("numptr and valptr point to variables with equal values\n");
    }

    if(numptr == valptr)
        printf("\nnumptr and valptr point to address %p\n", numptr);
    else
        printf("\n  numptr points to %p\n  valptr points to %p\n", numptr, valptr);
}

/*************************************************************
************                Output                ************

num is 3, val is 5
  numptr is 0x7fffff9d365c
  valptr is 0x7fffff9d3658

now num is 3, val is 3
numptr and valptr point to variables with equal values

  numptr points to 0x7fffff9d365c
  valptr points to 0x7fffff9d3658

*/
