/*
    author:  Preetam Ghosh
      date:  March 5, 2008
   purpose:  Demonstrate reading and writing to files.

   Note:  This example is based on example 10-3 in our textbook.


*/


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *infp;  /* pointer to file to be read */
    FILE *outfp; /* pointer to file to be written */

    int buffer;  /* variable to store the input byte */

    /* open files */
    if ( (infp = fopen("infile.txt", "r" )) == NULL )
    {
        printf("this file could not be opened for reading\n");
        exit(1);  /* we should exit if there is an error */
    }

    if ( (outfp = fopen("outfile.txt", "w" )) == NULL )
    {
        printf("this file could not be opened for writing\n");
        exit(1);  /* we should exit if there is an error */
    }

    /* A file is terminated with a character that we reference
       as EOF.  We want to keep getting characters until we
       reach EOF.                                           */

    /* get contents from one file and write them to another.
       we do this by getting a character from our input file
       followed by immediately writing it to our output file.*/
    while( ( buffer = getc(infp)) != EOF)
        putc( buffer, outfp);

    /* close files */
    fclose( infp );
    fclose( outfp );
}
