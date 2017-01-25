/********************************************************************
      author: Preetam Ghosh

        date: January 16, 2008
    
     purpose: compare two dates to determine which comes first

  pseudocode: at a high level, the solution is to

              1) compare years
              2) if necessary, compare months
              3) if necessary, compare days of month


              at a lower level, the solution is to

              compare years
              if they are equal
                  compare months
                  if they are equal
                      compare days
                      if they are equal
                          the dates are equal
                      else 
                          the days are not equal
                          so determine which came first
                  else 
                      the months are not equal
                      so determine which came first
              else
                  the years are not equal
                  so determine which came first
********************************************************************/

#include <stdio.h>

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

    if (y1 == y2)
    {
        if (m1 == m2)
        {
            if (d1 == d2)
                printf("the dates are the same");
            else 
                if (d1 < d2)
                    printf("used YMD -- date 1 came first\n");
                else
                    printf("used YMD -- date 2 came first\n");
        }
        else 
            if (m1 < m2)
                printf("used YM -- date 1 came first\n");
            else
                printf("used YM -- date 2 came first\n");
    }
    else 
        if (y1 < y2)
            printf("used Y -- date 1 came first\n");
        else
            printf("used Y -- date 2 came first\n");
}

/*******************************************************************
***********    output    *******************************************

used YMD -- date 2 came first

*******************************************************************/
