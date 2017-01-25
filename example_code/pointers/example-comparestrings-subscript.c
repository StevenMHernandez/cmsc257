/*
       author:  Preetam Ghosh
         date:  March 2, 2008
      purpose:  Compare strings to determine if a word occurs in a sentence.

 how it works:  Words are separated by a single space.  By detecting spaces,
                we can detect the beginning of a word.  Once a word is found,
                a pointer to the beginning of the word is passed to a function
                for comparison to the string we are searching for.
*/

#include <stdio.h>

void findDumpty(char *, int);

int main( void )
{
    char* text[] = {"Humpty Dumpty sat on a wall.",
                    "Humpty Dumpty had a great fall.",
                    "All the king's horses and all the king's men couldn't put Humpty back together again."}; 
    char* beginptr = *text;
    int i, offset = 0;
    int firstword = 1;
    
    for(i = 0; i < 3; i++)
    {
        while(text[i][offset] != '\0') /* for each sentence, continue search until the end */
        {
            if(text[i][offset] == ' ' || firstword)
            {
                if(firstword) /* if the first word of sentence, can't use space to find */
                    beginptr = text[i]; /* point to first word in sentence */
                else
                    beginptr = &text[i][offset+1]; /* point to the next word */
                findDumpty(beginptr, i);
                firstword = 0;
            }

            offset++;
        }
        printf("\n");
        offset = 0;
        firstword = 1;
    }
}

/* find location of Dumpty in string */
void findDumpty(char *a, int sentence)
{
    char dumpty[] = "Dumpty";
    int x = 0;

    while(dumpty[x] != '\0')
        if(dumpty[x] == a[x])
            x++;
        else
            return; /* return if the strings differ */

    printf("Dumpty has been found in sentence %d\n", sentence);
}

/********************************************************************
**********                Output                           **********

Dumpty has been found in sentence 0

Dumpty has been found in sentence 1

*/
