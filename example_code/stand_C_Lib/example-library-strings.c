/*
       name:  Preetam Ghosh

       date:  March 12, 2008

    purpose:  demonstrate the use of the Standard C library
*/

#include <stdio.h>
#include <string.h>

int main( void )
{
    char d[] = "Preetam Ghosh teaches CSS333.";
    char c[] = "  The class loves it.";
    char s1[] = "this is a string";
    char s2[] = "this is A string";
    char buffer[200]; /* allocate enough space for our two strings */
    char *word;
    char *delimiter = " "; /* use space as the delimiter between tokens */
    int diff;
    int wordlength;

    /****  demonstrate strcpy  ****/
    strcpy(buffer, d);  /* this copies the contents of array d 
                           to the beginning of the array buffer */


    /****  demonstrate strcat  ****/
    /*  don't do this since it doesn't allocate any additional memory
        char * somestring = "this is a string";
        strcat(somestring, "oops");
    */
    strcat(buffer, c); /* add the contents of array c to the end of 
                       buffer.  the end is where the terminating null is,
                       not the last allocated byte of memory           */
    printf(buffer);
    printf("\n\n");


    /****  demonstrate strcmp  ****/
    /*  strcmp(s1, s2) compares s1 and s2 on a character-by-character
        basis.  if the two strings are different, then the first
        character at which they differ will determine the value
        returned by strcmp().  A negative number will be returned if
        the differing character in s1 comes before the differing
        character in s2 in the ASCII table.  A positive number will
        be returned if s2 comes first.

        Example:  We have these two strings:

                    abcd
                    aBcd

                  that differ at the second character.  Since 'B' comes
                  before 'b' in the ASCII table, the second string comes
                  first and so a positive number will be returned 
                  by strcmp("abcd", "aBcd");
    */
    diff = strcmp(s1, s2);
    if (diff == 0)
        printf("the strings are equal\n\n");
    else if (diff < 0)
        printf("the first string comes first\n\n");
    else 
        printf("the second string comes first\n\n");


    /****  demonstrate strlen  ****/
    wordlength = strlen(d);
    printf("The string \"%s\" has \n", d);
    printf("%d characters (not counting the terminating null).\n\n", wordlength);


    /****  demonstrate strtok  ****/
    /* notice how to get the first word in array d, we pass d as the first
       argument to strtok().  To get each additional word, we pass NULL
       instead                                                          */
    printf("The tokens are\n");
    word = strtok(d, delimiter);
    while( word != NULL ) 
    {
        printf( "%s\n", word );
        word = strtok( NULL, delimiter );  /* get each additional word */
    }
}


/****************************************************************

Preetam Ghosh teaches CSS333.  The class loves it.

the second string comes first

The string "Preetam Ghosh teaches CSS333." has
29 characters (not counting the terminating null).

The tokens are
Preetam
Ghosh
teaches
CSS333.

*/
