/*
    author:  Preetam Ghosh
    
      date:  Wed Feb  6 10:11:16 CST 2008
      
   purpose:  Demonstrate initialization of arrays
*/
#include <stdio.h>

int main(void)
{
    int i;
    int first[4];  /* declared, but uninitialized */
    int second[5] = {1}; /* the first element is 
                            initialized to 1; the
                            remaining five elements will
                            be initialized to zero        */ 
    int third[10];

    /* print an uninitialized array.  We don't know what
       values to expect from this                         */
    for(i = 0; i < 4; i++)
        printf("first[%d] is %d\n", i, first[i]);

    printf("\n");

    /* print an array whose first member was initialized
       when the array was declared                        */
    for(i = 0; i < 5; i++)
        printf("second[%d] is %d\n", i, second[i]);

    printf("\n");

    third[9] = 99;

    /* print an array whose last member was initialized
       after the array was declared.  We don't know what
       to expect here.                                    */
    for(i = 0; i < 10; i++)
        printf("third[%d] is %d\n", i, third[i]);
}


/****************************************************
******************  Output  *************************

first[0] is 4196000
first[1] is 0
first[2] is 4195896
first[3] is 0

second[0] is 1
second[1] is 0
second[2] is 0
second[3] is 0
second[4] is 0

third[0] is 0
third[1] is 1597388920
third[2] is 13366
third[3] is 0
third[4] is 0
third[5] is 0
third[6] is 0
third[7] is 0
third[8] is 0
third[9] is 99

*/
