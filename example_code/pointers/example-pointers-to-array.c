/*
    Preetam Ghosh
    Sun Jun  8 16:29:14 CDT 2008

    Demonstrate using a pointer to an array to access the elements
    of the array.
*/

#include <stdio.h>

int main(void)
{
    int data1[] = {21, 22, 23, 24};
    int data2[][3] = { {41, 42, 43},
                       {44, 45, 46} };

    int *p11 = &data1[0];     /* pointer to 1st element of array */
    int *p12 = data1;         /* pointer to 1st element of array */
    int *p21 = &data2[0][0];  /* pointer to 1st element of 1D array */
    int (*p22)[3] = data2;    /* pointer to 1st 1D array in 2D array */
    int (*p23)[3] = data2;

    int i, k;

    for(i = 0; i < 4; i++)
        printf("%d  ", *p11++);

    printf("\n");

    for(i = 0; i < 4; i++)
        printf("%d  ", *p12++);

    printf("\n");

    for(i = 0; i < 6; i++)
        printf("%d  ", *p21++);

    printf("\n");

    for(i = 0; i < 2; i++)
        printf("%d  ", **p22++);

    printf("\n");

    for(i = 0; i < 2; i++)
    {
        for(k = 0; k < 3; k++)
            printf("%d  ", *(*p23 + k));
        p23++;
    }

    printf("\n");
}

/******************************************
***               Output                ***
21  22  23  24  
21  22  23  24  
41  42  43  44  45  46  
41  44  
41  42  43  44  45  46  
*/
