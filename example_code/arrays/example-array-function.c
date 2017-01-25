/*
    author:  Preetam Ghosh
    
      date:  Sun Feb  3 20:16:16 CST 2008
      
   purpose:  Demonstrate declaration of arrays
*/
#include <stdio.h>

/* function declaration */
int sumColumns(int [], int [], int);


int main(void)
{
    int i, sum;
    int BobsData[] = {30, 40, 50};
    int TomsData[] = {120, 60, 80};

    /*  loop through the index of the arrays */
    for(i=0; i<3; i++)
    {
        sum = sumColumns(BobsData, TomsData, i);
        printf("the sum of column %d is %d\n", i, sum);
    }
}

/* function definition */

int sumColumns(int first[], int second[], int index)
{
    int total;
    total = first[index] + second[index];
    return total;
}


/***********************************************************
********************   Output   ****************************

the sum of column 0 is 150
the sum of column 1 is 100
the sum of column 2 is 130

*/
