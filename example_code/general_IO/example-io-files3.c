/*
      author:  Preetam Ghosh
        date:  March 10, 2008
     purpose:  Demonstrate formatted reading from a file
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *inptr;
    char firstname[20];
    char lastname[20];
    char wholename[20];
    int age;
    int i;

    if ( (inptr = fopen("infile2.txt", "r" )) == NULL )
    {
        printf("this file could not be opened for reading\n");
        exit(1);  /* we should exit if there is an error */
    }

    /* this assumes we know in advance how many lines of
       information are in the file, which probably is not
       realistic                                          */
    for(i = 0; i < 3; i++)
    {
        /* the %s format specifier separates words by spaces   */
        fscanf(inptr, "%s %s %d", firstname, lastname, &age);
        printf("firstname: %s, lastname: %s, age: %d\n", firstname, lastname, age);
    }
    fclose( inptr );

    if ( (inptr = fopen("infile2.txt", "r" )) == NULL )
    {
        printf("this file could not be opened for reading\n");
        exit(1);  /* we should exit if there is an error */
    }

    printf("\n");
    for(i = 0; i < 3; i++)
    {
        /* by using %c with a width, we can capture an entire
           string including the whitespace between words      */
        fscanf(inptr, "%14c %d\n", wholename, &age);
        printf("name: %s, age: %d\n", wholename, age);
    }

    fclose( inptr );
}

/*****************************************************
***     input is a file called infile2.txt with    ***
***     the following contents                     ***

Bob Jones      50
John Smith     43
Lucy Johnson   25

***                   Output                       ***

firstname: Bob, lastname: Jones, age: 50
firstname: John, lastname: Smith, age: 43
firstname: Lucy, lastname: Johnson, age: 25

name: Bob Jones     , age: 50
name: John Smith    , age: 43
name: Lucy Johnson  , age: 25

*/

