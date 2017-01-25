/*
      author:  Preetam Ghosh
        date:  March 9, 2008
     purpose:  Demonstrate reading a string from the keyboard
       notes:  This is based on Example 5-4 in the textbook
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char input[101];  /* we assume we won't need to store more than 100 characters */
    char *ptr;

    printf("enter a string of text to be printed\n");
    ptr = fgets(input, 101, stdin);  /* stdin here means 'standard input', which in this
                                        case is what the user types on the keyboard */

    if (ptr != NULL)
        printf("you typed the string: %s", ptr);
        /* we could have used this instead:
                printf("also: %s", input);
        */
    else
    {
        printf("there was a problem getting input\n");
        exit(1);
    }
}

/*****************************************************
***                   Output                       ***

enter a string of text to be printed
My name is Preetam
you typed the string: My name is Preetam

*/

