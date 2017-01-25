/*
       name:  Preetam Ghosh

       date:  March 11, 2008

    purpose:  demonstrate the use of the Standard C library
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    double people = 22;
    double eggs = 8;

    printf("If we can transport four people per car, then to\n");
    printf("transport %.0f people we need %.0f cars.\n", people, ceil(people/4));
    printf("\n");
    printf("If we need three eggs to make a full batch of cookies,\n");
    printf("then with %.0f eggs we can make %.0f full batches of cookies.\n", eggs, floor(eggs/3));
}

/****************************************************************

If we can transport four people per car, then to
transport 22 people we need 6 cars.

If we need three eggs to make a full batch of cookies,
then with 8 eggs we can make 2 full batches of cookies.


*/
