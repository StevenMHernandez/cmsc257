/*
    this program demonstrates the use of pointer notation
    for accessing array values
*/

#include <stdio.h>

int main(void)
{
    int data[3][4] = { {1,  2,  3,  4},
                       {5,  6,  7,  8},
                       {9, 10, 11, 12} };

    printf("address of data is %p\n", data);
    printf("address of row 0 of data is %p\n", *data);
    /*  *(data + 1) says ``increment the address of data
        by one row's worth of bytes, then provide the
        address of that''                                 */
    printf("address of row 1 of data is %p\n", *(data + 1));
    printf("address of row 2 of data is %p\n", *(data + 2));
    printf("\n");

    /* notice these have the format *(array_name + row) + col   */
    printf("address of first element of row 0 is %p\n", *(data + 0) + 0);
    printf("address of first element of row 1 is %p\n", *(data + 1) + 0);
    printf("address of first element of row 2 is %p\n", *(data + 2) + 0);
    printf("\n");

    printf("address of second element of row 0 is %p\n", *(data + 0) + 1);
    printf("address of second element of row 1 is %p\n", *(data + 1) + 1);
    printf("address of second element of row 2 is %p\n", *(data + 2) + 1);
    printf("\n");

    /* when the amount being added is zero, we could leave out the zero */
    printf("address of *data + 1 is %p, *(data + 0) + 1 is %p\n", 
            *data + 1, *(data + 0) + 1);
    printf("\n");

    /* to get the value at an address, we need to include the dereference 
       operator again                                                     */
    /* notice these have the format *(*(array_name + row) + col)          */
    printf("the value of data[0][0] is %d\n", *(*data + 0) + 0);
    printf("the value of data[2][3] is %d\n", *(*(data + 2) + 3));
}

/**************************************
***********    Output    **************

address of data is 0xbff02060
address of row 0 of data is 0xbff02060
address of row 1 of data is 0xbff02070
address of row 2 of data is 0xbff02080

address of first element of row 0 is 0xbff02060
address of first element of row 1 is 0xbff02070
address of first element of row 2 is 0xbff02080

address of second element of row 0 is 0xbff02064
address of second element of row 1 is 0xbff02074
address of second element of row 2 is 0xbff02084

address of *data + 1 is 0xbff02064, *(data + 0) + 1 is 0xbff02064

the value of data[0][0] is 1
the value of data[2][3] is 12

*/
