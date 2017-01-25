/*
      author:  Preetam Ghosh
        date:  April 13, 2008
        file:  example-structures13.c
     purpose:  Read months and days from a file.
               If month ends in y, print the month.  If the number 
               of days is less than 31, print a statement saying such.
               If both conditions are true, then just have a single
               print statement saying both conditions are true.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char month[10]; 
    int days;
} MONTHDAYS;

void readFile(FILE *, MONTHDAYS m[]);
void processMonths(MONTHDAYS m[]);
int endY(char *);

int main(void)
{
    MONTHDAYS md[12]; 
    FILE *inptr;

    if ( (inptr = fopen("months.txt", "r" )) == NULL )
    {
        printf("this file could not be opened for reading\n");
        exit(1);  /* we should exit if there is an error */
    }

    readFile(inptr, md);

    fclose( inptr );
}

void readFile(FILE *inptr, MONTHDAYS m[])
{
    int i = 0;
    while( fscanf( inptr, "%s %d\n", m[i].month, &m[i].days) != EOF) 
        i++;
    
    processMonths(m);

}

void processMonths(MONTHDAYS m[])
{
    /* 
       If month ends in y, print the month.  If the number 
       of days is less than 31, print a statement saying such.
    */
    int i;

    for(i = 0; i < 12; i++)
        if( endY(m[i].month) && m[i].days < 31)
            printf("%s ends in y and has %d days\n", m[i].month, m[i].days);
        else
        {
            if( endY(m[i].month) )
                printf("%s ends in y\n", m[i].month);
            if(m[i].days < 31)
                printf("%s has %d days\n", m[i].month, m[i].days);
        }
}

int endY(char *word)
{
    int i = 0;
    char last;

    while(word[i] != '\0')
    {
        last = word[i];
        i++;
    }

    if (last == 'y')
        return 1;
    else
        return 0;
}

/*****************************************************
***                   Output                       ***

January ends in y
February ends in y and has 28 days
April has 30 days
May ends in y
June has 30 days
July ends in y
September has 30 days
November has 30 days

*/
