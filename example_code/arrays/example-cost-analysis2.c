/*
    problem:     Given the costs to produce a product and the
                 price we can sell the finished product for,
                 which product will maximize our profit?

                 The function for calculating profit is
                   profit = sale price - (labor cost)*(hours of labor)
                 where labor cost = $10/hour

                 However, there is a machine that will cut labor time
                 in half, but it rents for a cost of $15 per item produced.

                    Choice #   Hours of labor   sale price (in $)
                    ---------------------------------------------
                       1              1               12
                       2              2               25
                       3              2               27
                       4              3               36
                       5              4               45
                       6              1               13
                       7              3               32

    pseudocode:  tables can be viewed as a matrix, which in
                 programming terms is a 2D array
                 for each combination of hours of labor and
                 sale price
                     calculate profit with and without machine
                     use calculation that maximizes profit

    NOTE:  
*/

#include <stdio.h>

int main(void)
{
    int i;
    double profit, profit1, profit2;
    double max_profit = 0;
    int choice;
                     /* hours, sale price */
    int data[7][2] = { {1, 12},
                       {2, 25},
                       {2, 27},
                       {3, 36},
                       {4, 45},
                       {1, 13},
                       {3, 32} };

    for(i = 0; i < 7; i++)
    {
        profit1 = data[i][1] - 10*data[i][0];  /* without machine */
        profit2 = data[i][1] - (10*(data[i][0]/2.0) + 15); /* with machine */

        printf("Item #%d has potential profits of $%5.2f and $%5.2f per item.\n", 
            i+1, profit1, profit2);

        /* determine whether or not using the machine increases the profit */
        if (profit1 > profit2)
            profit = profit1;
        else
            profit = profit2;

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

Item #1 has potential profits of $ 2.00 and $-8.00 per item.
Item #2 has potential profits of $ 5.00 and $ 0.00 per item.
Item #3 has potential profits of $ 7.00 and $ 2.00 per item.
Item #4 has potential profits of $ 6.00 and $ 6.00 per item.
Item #5 has potential profits of $ 5.00 and $10.00 per item.
Item #6 has potential profits of $ 3.00 and $-7.00 per item.
Item #7 has potential profits of $ 2.00 and $ 2.00 per item.

The profit-maximizing choice is 5
*/

