/*
    author:  Preetam Ghosh
      date:  March 5, 2008
   purpose:  Demonstrate writing to a file.

*/


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *outfp; 
    char buffer[] = "this is a line\nthis is another line\n";
    int counter = 0;

    if ( (outfp = fopen("outfile.txt", "w" )) == NULL )
    {
        printf("this file could not be opened for writing\n");
        exit(1);  /* we should exit if there is an error */
    }
 
    /* keep passing characters to the file pointer until
       we reach the end of the string                    */
    while( buffer[counter] != '\0')
    {
        /* putc() expects an int, so we cast  */
        putc((int)buffer[counter], outfp);
        counter++;
    }

    fclose( outfp );
}

