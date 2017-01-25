/*
      author:  Preetam Ghosh
        date:  April 16, 2008
        file:  joinfiles.c
     purpose:  Demonstrate reading a group of files and combining 
               the columns.

       notes:  This program assumes both files have the same
               number of rows.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *inptr1, *inptr2, *outptr;
    char buffer1[100];
    char buffer2[100];
    char outbuffer[200];
    char temp[100];
    char *word;
    char *delimiter = "\n";

    if ( argc != 4 )
        if (argc < 4)
        {
            printf("usage:  joinfiles  infile1  infile2  outfile\n");
            printf("example:  joinfiles  report1.txt report2.txt report-total.txt\n");
            exit(1);
        }
        else if (argc > 4)
        {
            printf("you provided too many parameters\n");
            exit(1);
        }

    if ( (inptr1 = fopen(argv[1], "r" )) == NULL )
    {
        printf("%s could not be opened for reading\n", argv[1]);
        exit(1);  
    }

    if ( (inptr2 = fopen(argv[2], "r" )) == NULL )
    {
        printf("%s could not be opened for reading\n", argv[2]);
        exit(1);  
    }

    if ( (outptr = fopen(argv[3], "w" )) == NULL )
    {
        printf("%s could not be opened for writing\n", argv[3]);
        exit(1);  
    }

    while( fgets(temp, 100, inptr1) != NULL )
    {
        word = strtok(temp, delimiter); /* remove the newline */
        strcpy(buffer1, word);

        fgets(temp, 100, inptr2);
        word = strtok(temp, delimiter); /* remove the newline */
        strcpy(buffer2, word);

        fprintf(outptr, "%s, %s\n", buffer1, buffer2);
    }  

    fclose( inptr1 );
    fclose( inptr2 );
    fclose( outptr );
}

/*****************************************************
***                 infile1.txt                    ***

John Abrams
Tom Brady
Susan Collins
George Douglas
Jennifer Epson
Mary Foster


/*****************************************************
***                 infile2.txt                    ***

30068
3735
31916
4478
15878
26202

/*****************************************************
***              running the program               ***

$ joinfiles
usage:  joinfiles  infile1  infile2  outfile
example:  joinfiles  report1.txt report2.txt report-total.txt

$ cat outfile.txt
John Abrams, 30068
Tom Brady, 3735
Susan Collins, 31916
George Douglas, 4478
Jennifer Epson, 15878
Mary Foster, 26202

*/


