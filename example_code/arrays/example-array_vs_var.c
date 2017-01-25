/*
    Preetam Ghosh
    Thu May 29 14:57:06 CDT 2008

    Bubblsort using arrays and single variables.
 
    pseudocode for bubblesort:
              1) beginning with the first two numbers
              2) compare the numbers
                 if first number > second number
                   swap the positions
              3) shift over to the second and third numbers
                 
                 repeat this process until no swapping occurs
*/

#include <stdio.h>

void printArray(int data[]);

int main(void)
{
    int data[] = {9, 4, 5, 3};
    int a = 9, b = 4, c = 5, d = 3;
    int i, temp, still_changing;

    /*  bubblesort using single variables  */
    printf("%d, %d, %d, %d\n", a, b, c, d);

    do
    {
        still_changing = 0;

        if (b < a)
        {
            temp = a;
            a = b;
            b = temp;
            still_changing = 1;
            printf("%d, %d, %d, %d\n", a, b, c, d);
        }

        if (c < b)
        {
            temp = b;
            b = c;
            c = temp;
            still_changing = 1;
            printf("%d, %d, %d, %d\n", a, b, c, d);
        }

        if (d < c)
        {
            temp = c;
            c = d;
            d = temp;
            still_changing = 1;
            printf("%d, %d, %d, %d\n", a, b, c, d);
        }
    } while (still_changing);
    
    /*  bubblesort using array  */
    printf("\nbubblesort using array\n");
    printArray(data);

    do
    {
        still_changing = 0;

        for(i = 0; i < 3; i++)
            if(data[i+1] < data[i])
            {
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                still_changing = 1;
                printArray(data);
            }

    } while (still_changing);
}

void printArray(int data[])
{
    int i;
    for(i = 0; i < 4; i++)
        if(i < 3)
            printf("%d, ", data[i]);
        else
            printf("%d\n", data[i]);
}


/*
[pghosh@orca CSS333]$ ./a.out 
20
18
16
14
12
10
8
6
4
[pghosh@orca CSS333]$ 


*/
