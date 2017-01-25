/* pseudocode:
        get a string
        check each character to determine if it
        is in the uppercase range.
        if so,
            change to lowercase
*/
#include <stdio.h>

void lowercase(char [], int);

int main (void)
{
    char name[] = "My name is Preetam Ghosh.";
    int stringsize;

    printf("The string is \n\n  %s\n\n", name);

    stringsize = sizeof(name)/sizeof(char);
    lowercase(name, stringsize);

    printf("The string is now\n\n  %s\n\n", name);
}

void lowercase(char input[], int size)
{
    /* Notes:  A--Z is 65--90, a--z is 97--122

         Uppercase letters will have a decimal value
         of at least 65 but will be no larger than 90.

         Remember that strings conclude with a null
         character, so a string that takes n bytes of
         storage will have n-1 actual characters.
    */
    int i;

    for(i = 0; i < size - 1; i++)
        if(input[i] >= 65 && input[i] <= 90)
            input[i] += 32;
}

/*************************************************************
*************************   Output   *************************

The string is 

  My name is Preetam Ghosh.

The string is now

  my name is preetam ghosh.

*/
