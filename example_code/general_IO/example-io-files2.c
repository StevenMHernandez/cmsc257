/*
      author:  Preetam Ghosh
        date:  March 10, 2008
     purpose:  Demonstrate formatted writing to a file
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *outptr;
    double data[] = {1.8, 2.345, 0.92};
    int i;

    if ( (outptr = fopen("outfile2.txt", "w" )) == NULL )
    {
        printf("this file could not be opened for writing\n");
        exit(1);  /* we should exit if there is an error */
    }

    for(i = 0; i < 3; i++)
        fprintf(outptr, "%5.3f\n", data[i]);

    fclose( outptr );
}

/*****************************************************
***     Output is a file called outfile2.txt with  ***
***     the following contents                     ***

1.800
2.345
0.920

*/

