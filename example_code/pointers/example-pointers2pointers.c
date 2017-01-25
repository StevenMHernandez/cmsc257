#include <stdio.h>

int main(void)
{
    int num = 5;  
    int* numptr = &num;  
    int** ptr2 = &numptr;  /* notice the two asterisks */

    printf("  &ptr2 is %p\n\n", &ptr2);

    printf("&numptr is %p\n", &numptr);
    printf("   ptr2 is %p\n\n", ptr2);

    printf("   &num is %p\n", &num);
    printf(" numptr is %p\n", numptr);
    printf("  *ptr2 is %p\n\n", *ptr2);

    printf("    num is %d\n", num);
    printf("*numptr is %d\n", *numptr);
    printf(" **ptr2 is %d\n", **ptr2);
}

/*********************************************************
***********               Output               ***********

  &ptr2 is 0xbfb4b15c

&numptr is 0xbfb4b160
   ptr2 is 0xbfb4b160

   &num is 0xbfb4b164
 numptr is 0xbfb4b164
  *ptr2 is 0xbfb4b164

    num is 5
*numptr is 5
 **ptr2 is 5

*/

