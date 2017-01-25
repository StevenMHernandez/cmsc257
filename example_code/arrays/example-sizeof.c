/*
     author:  Preetam Ghosh,

       date:  Sat Feb  2 17:53:34 CST 2008

    purpose:  demonstrate using sizeof() to determine the memory
              requirements of a data object
*/

#include <stdio.h>

int main(void)
{
    int someint = 4;
    int numOfElements;
    long double somedouble = 4.5;
    double data[] = {3.4, 2.5, 4.1, 1.2, 2.8, 3.7};

    printf("sizeof(int) is %d\n", sizeof(int));
    printf("sizeof(someint) is %d\n", sizeof(someint));
    printf("sizeof(somedouble) is %d\n", sizeof(somedouble));

    /* each element in an array will require the number of bytes required
       for its data type.  Therefore, to determine the number of elements
       in an array, divide the total memory by the memory required by 
       the data types */
    numOfElements = sizeof(data)/sizeof(double);
    printf("sizeof(double) and sizeof(data) are %d and %d\n", sizeof(double), sizeof(data));
    printf("number of elements of data is %d\n", numOfElements);
}

/******************************************************************
***************  Output on a 64-bit machine  **********************
*******  this could be different on other hardware  ***************

sizeof(int) is 4
sizeof(someint) is 4
sizeof(somedouble) is 16
sizeof(double) and sizeof(data) are 8 and 48
number of elements of data is 6

*/
