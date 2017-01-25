/*
      author:  Preetam Ghosh
        date:  April 7, 2008
     purpose:  Read a file, tokenizing each line.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *inptr;
    char buffer[200]; /* allocate space for a line */
    char *word;
    char *store;
    char *month;
    char *delimiter = ","; /* use comma as the delimiter between tokens */

    if ( (inptr = fopen("sales.txt", "r" )) == NULL )
    {
        printf("this file could not be opened for reading\n");
        exit(1);  /* we should exit if there is an error */
    }

    /* read each line until the end of the file */
    while( fgets(buffer, 200, inptr) != NULL )
    {
        /* tokenize line */
        word = strtok(buffer, delimiter);

        /* loop through the tokens -- useful if the number
           of tokens is unknown in advance                 */
        while( word != NULL ) 
        {
            printf( "%s\n", word );
            word = strtok( NULL, delimiter );  /* get each additional word */
        }
    }  
    fclose( inptr );

    /*********************************************************/
    /*  we can reopen a file for reading  */
    if ( (inptr = fopen("sales.txt", "r" )) == NULL )
    {
        printf("this file could not be opened for reading\n");
        exit(1);  /* we should exit if there is an error */
    }

    /* read each line until the end of the file */
    while( fgets(buffer, 200, inptr) != NULL )
    {
        /* tokenize line */
        store = strtok(buffer, delimiter);
        month = strtok( NULL, delimiter );

        /* notice the extra space before the month */
        printf( "store=%s  month=%s\n", store, month );
    }  
    fclose( inptr );
}

/*************************************************
***                sales.txt                   ***

Best Buy, August, 1267
Home Depot, August, 4592
Best Buy, September, 941
Walmart, January, 31008

*/


/*************************************************
***                 Output                     ***

Best Buy
 August
 1267

Home Depot
 August
 4592

Best Buy
 September
 941

Walmart
 January
 31008

store=Best Buy  month= August
store=Home Depot  month= August
store=Best Buy  month= September
store=Walmart  month= January

*/
