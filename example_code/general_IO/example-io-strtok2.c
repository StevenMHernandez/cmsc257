/*
      author:  Preetam Ghosh
        date:  April 7, 2008
     purpose:  Read a file, tokenizing each line.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char text[] = "This is a string.  Here is another string.";
    char somestring[] = "What happens when we parse this string?";
    char* ptr[4];  /* we magically know that we will need 4 pointers */
    char* word;
    char* delperiod = ".";
    char* delspace = " ";
    char* delmany = "ep ";
    int i;

    word = strtok(text, delperiod);
    printf("First we tokenize using a period:  %s\n", word);

    printf("\n\nThen we tokenize the first token using spaces:\n\n");
    ptr[0] = strtok(word, delspace);

    for(i = 1; i < 4; i++)
        ptr[i] = strtok( NULL, delspace );

    for(i = 0; i < 4; i++)
        printf( "%s\n", ptr[i] );

    /***************************************************/

    printf("\n\n");
    word = strtok(somestring, delmany);

    /* loop through the tokens -- useful if the number
       of tokens is unknown in advance                 */
    while( word != NULL ) 
    {
        printf( "%s\n", word );
        word = strtok( NULL, delmany );  /* get each additional word */
    }
}


/*************************************************
***                 Output                     ***

First we tokenize using a period:  This is a string


Then we tokenize the first token using spaces:

This
is
a
string


What
ha
ns
wh
n
w
ars
this
string?

*/


