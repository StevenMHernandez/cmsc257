/*
      author:  Preetam Ghosh
        date:  March 9, 2008
     purpose:  Demonstrate reading and writing to files
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char input[30];  /* we assume we won't need to store more than 30 characters */
    FILE *inptr;
    FILE *outptr;

    if ( (inptr = fopen("infile1.txt", "r" )) == NULL )
    {
        printf("this file could not be opened for reading\n");
        exit(1);  /* we should exit if there is an error */
    }

    if ( (outptr = fopen("outfile1.txt", "w" )) == NULL )
    {
        printf("this file could not be opened for writing\n");
        exit(1);  /* we should exit if there is an error */
    }

    while( fgets(input, 30, inptr) != NULL )
        fputs(input, outptr);

    fclose( inptr );
    fclose( outptr );
}

/*****************************************************
***                   Output                       ***


*/

