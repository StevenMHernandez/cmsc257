/********************************************************************
      author: Preetam Ghosh

        date: January 30, 2008
    
     purpose: demonstrate use of function to compare two dates in 
              order to determine which comes first
********************************************************************/

#include <stdio.h>

/*****************  Function Declarations  *************************/
void cmpdates(int m1, int d1, int y1, int m2, int d2, int y2);


int main(void)
{
    /* date 1 */
    int y1 = 2008;
    int m1 = 3;
    int d1 = 10;

    /* date 2 */
    int y2 = 2008;
    int m2 = 3;
    int d2 = 4;

    /* date 3 */
    int y3 = 2007;
    int m3 = 3;
    int d3 = 4;

    cmpdates(m1, d1, y1, m2, d2, y2);
    cmpdates(m3, d3, y3, m2, d2, y2);
    cmpdates(m3, d3, y3, m1, d1, y1);
}

/************************  Functions  ******************************/

/*
  function name: cmpdates()
        purpose: compare two dates to determine which comes first
          input: integers representing the two years in M/D/Y format
        returns: nothing
*/
void cmpdates(int m1, int d1, int y1, int m2, int d2, int y2)
{
    if (y1 == y2)
    {
        if (m1 == m2)
        {
            if (d1 == d2)
                printf("the dates are the same");
            else 
                if (d1 < d2)
                    printf("used YMD -- %d/%d/%d comes before %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
                else
                    printf("used YMD -- %d/%d/%d comes before %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
        }
        else 
            if (m1 < m2)
                printf("used YM -- %d/%d/%d comes before %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
            else
                printf("used YM -- %d/%d/%d comes before %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
    }
    else 
        if (y1 < y2)
            printf("used Y -- %d/%d/%d comes before %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
        else
            printf("used Y -- %d/%d/%d comes before %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
}

/*******************************************************************
***********    output    *******************************************

used YMD -- 3/4/2008 comes before 3/10/2008
used Y -- 3/4/2007 comes before 3/4/2008
used Y -- 3/4/2007 comes before 3/10/2008

*******************************************************************/
