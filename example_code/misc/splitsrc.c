/*   Example of source code split over several files.  The three
separate files are shown together here.

/*************************************************************/
/*                       mainfile.c                          */

#include <stdio.h>
#include "myfunctions.h"

int main(void)
{
    int data[6] = {1, 2, 3, 4, 5, 6};
    double avg;

    avg = calcAvg(data, 6);

    printf("The average is %5.2f\n", avg);
}

/*                                                           */
/*************************************************************/

/*************************************************************/
/*                      myfunctions.h                        */

double calcAvg(int *, int);

/*                                                           */
/*************************************************************/

/*************************************************************/
/*                      myfunctions.c                        */

#include <stdio.h>

double calcAvg(int *a, int r)
{
    int i;
    double sum = 0;

    for(i = 0; i < r; i++)
        sum += *(a + i);

    return sum/r;
}

/*                                                           */
/*************************************************************/
