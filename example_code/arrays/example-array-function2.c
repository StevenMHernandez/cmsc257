/*
    author:  Preetam Ghosh
    
      date:  Mon Feb  4 11:00:51 CST 2008
      
   purpose:  Demonstrate arrays as function parameters
*/
#include <stdio.h>

void changeArray(float [], int);

int main(void)
{
    int some_int = 7;
    float myData[] = {3.5, 4.0, 9.34};  
    
    printf("The last member of myData is %3.2f, some_int is %d\n", myData[2], some_int);

    changeArray(myData, some_int);  /* pass the array and int to the function */

    printf("Now the last member of myData is %3.2f, some_int is %d\n", myData[2], some_int);
}

void changeArray(float data[], int input)
{
    /* here we attempt to change our original values */
    data[2] = 6;
    input = 90;
    printf("Inside the function the last member of myData is %3.2f, some_int is %d\n", 
           data[2], input);
}


/***************************************************************************
****************************  Output  **************************************

The last member of myData is 9.34, some_int is 7
Inside the function the last member of myData is 6.00, some_int is 90
Now the last member of myData is 6.00, some_int is 7

*/
