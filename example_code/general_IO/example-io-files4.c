/*
      author:  Preetam Ghosh
        date:  March 10, 2008
     purpose:  Demonstrate reading a file whose name was passed as an argument
               
       notes:  argc is the count of the number of command-line arguments (including
                 the executable file)
               argv is a pointer to an array of the command-line arguments
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *inptr;
    char buffer[10];
    double input;
    double sum = 0;
    int count = 0;

    if ( argc != 2 )
        if (argc == 1)
        {
            printf("you must provide the name of a file to read\n");
            exit(1);
        }
        else
        {
            printf("you provided more than one filename\n");
            exit(1);
        }

    /* open a file for reading */
    if ( (inptr = fopen(argv[1], "r" )) == NULL )
    {
        printf("this file could not be opened for reading\n");
        exit(1);  /* we should exit if there is an error */
    }

    /* each line of the file is read by fgets() until the
       end of the file.  for each line, sscanf() is used to
       perform a formatted read of the line                */
    while ( fgets( buffer, 10, inptr) != NULL)
    {
        sscanf(buffer, "%lf", &input);
        sum += input;
        count++;
    }

    printf("the average is %f\n", sum/count);

    fclose( inptr );
}

/*****************************************************
***     input is a file called infile3.txt with    ***
***     the following contents                     ***

1.2
8.9
7.34

******************************************************
***                 output                         ***

the average is 5.813333

*/

