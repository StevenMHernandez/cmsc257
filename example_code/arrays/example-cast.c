/*
     author:  Preetam Ghosh,

       date:  Sat Feb  2 17:53:34 CST 2008

    purpose:  demonstrate the effects of casting from one type to another
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int x = 9, y = 4;
    double eToPower;
    float answer;

    answer = x/y;   /* this is integer division, so the answer 
                       will be an integer*/
 
    printf("answer is %3.2f\n", answer);

    answer = (float)x/y;
    printf("answer after casting is %3.2f\n", answer);


    /* the arguments to variable are specific types, so if
       your variables are not already of these types you may
       get warnings from the compiler unless you cast 
    */

    /* the function for raising e to a power expects a double, so
       I am casting the int y to a double */
    eToPower = exp( (double) y );
    printf("e^4 is %f\n", eToPower);
}

/******************************************************************
***************              Output          **********************

answer is 2.00
answer after casting is 2.25
e^4 is 54.598150

*/
