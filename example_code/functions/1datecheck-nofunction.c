/********************************************************************
      author: Preetam Ghosh

        date: September 14, 2008
    
     purpose: demonstrate how a function would be more appropriate
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


    if (y3 == y2)
    {
        if (m3 == m2)
        {
            if (d3 == d2)
                printf("the dates are the same");
            else 
                if (d3 < d2)
                    printf("used YMD -- %d/%d/%d comes before %d/%d/%d\n", m3, d3, y3, m2, d2, y2);
                else
                    printf("used YMD -- %d/%d/%d comes before %d/%d/%d\n", m2, d2, y2, m3, d3, y3);
        }
        else 
            if (m3 < m2)
                printf("used YM -- %d/%d/%d comes before %d/%d/%d\n", m3, d3, y3, m2, d2, y2);
            else
                printf("used YM -- %d/%d/%d comes before %d/%d/%d\n", m2, d2, y2, m3, d3, y3);
    }
    else 
        if (y3 < y2)
            printf("used Y -- %d/%d/%d comes before %d/%d/%d\n", m3, d3, y3, m2, d2, y2);
        else
            printf("used Y -- %d/%d/%d comes before %d/%d/%d\n", m2, d2, y2, m3, d3, y3);


    if (y3 == y1)
    {
        if (m3 == m1)
        {
            if (d3 == d1)
                printf("the dates are the same");
            else 
                if (d3 < d1)
                    printf("used YMD -- %d/%d/%d comes before %d/%d/%d\n", m3, d3, y3, m1, d1, y1);
                else
                    printf("used YMD -- %d/%d/%d comes before %d/%d/%d\n", m1, d1, y1, m3, d3, y3);
        }
        else 
            if (m3 < m1)
                printf("used YM -- %d/%d/%d comes before %d/%d/%d\n", m3, d3, y3, m1, d1, y1);
            else
                printf("used YM -- %d/%d/%d comes before %d/%d/%d\n", m1, d1, y1, m3, d3, y3);
    }
    else 
        if (y3 < y1)
            printf("used Y -- %d/%d/%d comes before %d/%d/%d\n", m3, d3, y3, m1, d1, y1);
        else
            printf("used Y -- %d/%d/%d comes before %d/%d/%d\n", m1, d1, y1, m3, d3, y3);

}

/*******************************************************************
***********    output    *******************************************

used YMD -- 3/4/2008 comes before 3/10/2008
used Y -- 3/4/2007 comes before 3/4/2008
used Y -- 3/4/2007 comes before 3/10/2008

*******************************************************************/
