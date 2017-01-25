/*
       author:  Preetam Ghosh
 
         date:  Sun Mar  2 15:49:16 CST 2008
 
      purpose:  given an unsorted array of doubles, determine the 
                sort order without sorting the integers in place, 
                i.e., retain the original order
 
                Why not just copy the original array and sort it?
                There may be a need to conserve memory, so by only
                sorting the indices (which are ints) we can conserve
                space.

 how it works:  Instead of sorting the original array values,
                an array of the indices of the original values
                is sorted.  To produce the list of sorted values,
                we move through the index printing data[index[i]]
                For example, if the smallest value in the array is
                the third value (with an index of 2), then in our
                array of indices it will be first.  Therefore,
                index[0] = 2 and 
                data[index[0]] = data[2] = smallest value
 
      example:  original values are
                   data[] = {8.5, 7.9, 2.3, 10.4, 7.6}
                 indices --> 0    1    2     3    4
                the sorted values are
                   data[2], data[4], data[1], data[0], data[3]
                so the array of indices would be
                   index[] = {2, 4, 1, 0, 3};

                from this we get that
                   data[index[0]] = data[2] =  2.3
                   data[index[1]] = data[4] =  7.6
                   data[index[2]] = data[1] =  7.9
                   data[index[3]] = data[0] =  8.5
                   data[index[4]] = data[3] = 10.4
*/

#include <stdio.h>

void bubblesort(double *, int *, int);
void swap(int *, int *); /* for swapping index values */

int main(void)
{
    double grades[] = {74.190, 12.160, 72.409, 19.862, 37.791, 
                       55.895, 78.529, 25.512, 60.139, 80.493,
                       56.620, 62.912, 32.951, 33.637, 84.340, 
                       39.658, 27.387, 35.990, 56.257, 43.810};
    int index[20];  /* array to hold the sorted position of each 
                       element of data                          */
    int i, j;
    int size = 20;

    for(i = 0; i < size; i++)
        *(index + i) = i;  /* set the initial index values */

    bubblesort(grades, index, size);

    printf("the original values are:\n");
    for(i = 0; i < size; i++)
        printf("index:%3d, %6.3f\n", i, *(grades + i));

    printf("\n\nthe indices in the order matching the sorted values:\n");
    for(i = 0; i < size; i++)
        printf("%d, ", *(index + i));

    printf("\n\nthe sorted values are:\n");
    for(i = 0; i < size; i++)
        /* for each value in an index, find the corresponding
           original value to print                           */
        printf("index:%3d, %6.3f\n", *(index + i), *(grades + *(index + i)));
        /* in the previous line, the offset to the address of grades is the
           value of the index, i.e., the position in sorted order          */
}

/*
    function: bubblesort()
       input: address of array of doubles
              address of array of ints
              size of array (both arrays should be the same size)
      output: nothing
*/
void bubblesort(double *data, int *index, int size)
{
    int still_changing = 1;  /* flag to know when to stop the comparisons */
    int i;

    while(still_changing)
    {
        still_changing = 0;
        for(i = 0; i < (size - 1); i++)
        {
            /*  in subscript notation this would be

                if( data[index[i]] > data[index[i + 1]] )
            */
            if( *(data + *(index + i)) > *(data + *(index + i + 1)) )
            {
                swap(index + i, index + i + 1);
                still_changing = 1;
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


/***************************************************************
*************                Output                *************

the original values are:
index:  0, 74.190
index:  1, 12.160
index:  2, 72.409
index:  3, 19.862
index:  4, 37.791
index:  5, 55.895
index:  6, 78.529
index:  7, 25.512
index:  8, 60.139
index:  9, 80.493
index: 10, 56.620
index: 11, 62.912
index: 12, 32.951
index: 13, 33.637
index: 14, 84.340
index: 15, 39.658
index: 16, 27.387
index: 17, 35.990
index: 18, 56.257
index: 19, 43.810


the indices in the order matching the sorted values:
1, 3, 7, 16, 12, 13, 17, 4, 15, 19, 5, 18, 10, 8, 11, 2, 0, 6, 9, 14, 

the sorted values are:
index:  1, 12.160
index:  3, 19.862
index:  7, 25.512
index: 16, 27.387
index: 12, 32.951
index: 13, 33.637
index: 17, 35.990
index:  4, 37.791
index: 15, 39.658
index: 19, 43.810
index:  5, 55.895
index: 18, 56.257
index: 10, 56.620
index:  8, 60.139
index: 11, 62.912
index:  2, 72.409
index:  0, 74.190
index:  6, 78.529
index:  9, 80.493
index: 14, 84.340

*/
