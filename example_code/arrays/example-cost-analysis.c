/*
    problem:     Given the hours to produce a product and the
                 price we can sell the finished product for,
                 which product will maximize our profit?
                 
                  The function for calculating profit is
                   profit = sale price - (labor cost)*(hours of labor)
                 where labor cost = $10/hour

                    Choice #   Hours of labor   sale price (in $)
                    ---------------------------------------------
                       1              1               20
                       2              2               29
                       3              2               27
                       4              3               36
                       5              4               41
                       6              1               19
                       7              3               32

    pseudocode:  tables can be viewed as a matrix, which in
                 programming terms is a 2D array
                 for each combination of hours of labor and
                 sale price
                         calculate profit

    NOTE:  
*/

#include <stdio.h>

int main(void)
{
    int i, profit;
    int max_profit = 0;
    int choice;
                     /* hours, sale price */
    int data[7][2] = { {1, 20},
                       {2, 29},
                       {2, 27},
                       {3, 36},
                       {4, 41},
                       {1, 19},
                       {3, 32} };

    for(i = 0; i < 7; i++)
    {
        profit = data[i][1] - 10*data[i][0];
        printf("Item #%d has a profit of $%2d per item.\n", i+1, profit);
        if (profit > max_profit)
        {
            max_profit = profit;
            choice = i + 1;
        }
    }
    printf("\nThe profit-maximizing choice is %d\n", choice);
}

/**************************************************************
*********************   Output   ******************************

Item #1 has a profit of $10 per item.
Item #2 has a profit of $ 9 per item.
Item #3 has a profit of $ 7 per item.
Item #4 has a profit of $ 6 per item.
Item #5 has a profit of $ 1 per item.
Item #6 has a profit of $ 9 per item.
Item #7 has a profit of $ 2 per item.

The profit-maximizing choice is 1

*/

