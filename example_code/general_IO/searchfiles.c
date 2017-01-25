/*
      author:  Preetam Ghosh
        date:  April 16, 2008
        file:  searchfiles.c
     purpose:  Demonstrate reading a group of files based upon
               a common naming scheme
               
       notes:  a better approach would be to use a library that
               allows for globbing file names

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *inptr;
    char buffer[100];
    char filename[30];
    char *word;
    char *delimiter = " ";
    int sum = 0;
    int value;

    int i;

    if ( argc != 4 )
        if (argc < 4)
        {
            printf("usage:  searchfiles file_name_prefix  file_extension  number_of_files\n");
            printf("example:  searchfiles  input  txt  5\n");
            exit(1);
        }
        else if (argc > 4)
        {
            printf("you provided too many parameters\n");
            exit(1);
        }

    for(i = 1; i <= atoi(argv[3]); i++)
    {
       /*  create filename from command-line arguments  */
        sprintf( filename, "%s%d.%s", argv[1], i, argv[2] );
        
        if ( (inptr = fopen(filename, "r" )) == NULL )
        {
            printf("this file could not be opened for reading\n");
            exit(1);  
        }

        while( fgets(buffer, 100, inptr) != NULL )
        {
            /* tokenize line */
            word = strtok(buffer, delimiter);
            if (strcmp(word, "Total") == 0 )
            {
                value = atoi( strtok( NULL, delimiter ) );
                sum += value;
                printf("Total from %s is %d\n", filename, value);
            }
        }  

        fclose( inptr );
    }
    printf("\nThe overall total is %d.\n", sum);
}

/*****************************************************
***                 log1.txt with                  ***

        TARGET

 September        7250
 June            20917
 December        32963
 March           33329
 January         15342
-----------------------
 Total           10980

/*****************************************************
***                 log2.txt with                  ***

       BEST BUY

 June            10191
 April           10103
 July            17740
 May             26486
 November        23448
 March            5614
-----------------------
 Total           93582

/*****************************************************
***                 log3.txt with                  ***

        WALMART

 October         12121
 January         16212
-----------------------
 Total           28333

/*****************************************************
***                 log4.txt with                  ***

      HOME DEPOT

 August          14725
-----------------------
 Total           14725

******************************************************
***                 output                         ***

searchfiles log txt 4
Total from log1.txt is 10980
Total from log2.txt is 93582
Total from log3.txt is 28333
Total from log4.txt is 14725

The overall total is 147620.

*/


