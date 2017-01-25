/*
    name:  Preetam Ghosh
    date:  Mon Nov  3 23:37:27 CST 2008
    CSE 1311

    Generate a calendar for 2008.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHeader(int, FILE*);
int calcDay(int);

int main(void)
{
    FILE* outptr;
    int numDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int current;  /* months are 0-11 */
    int begin, i;
    int dayCounter;

    if ( (outptr = fopen("calendar.txt", "w" )) == NULL )
    {
        printf("this file could not be opened for writing\n");
        exit(1);  /* we should exit if there is an error */
    }
    
    for(current = 0; current < 12; current++)
    {
        dayCounter = 0;
        begin = calcDay(current);
    
        /* print month name and days of week */
        printHeader(current, outptr);
    
        /* month may not begin on Sunday, so pad with spaces */
        for(i = 0; i < begin; i++)
        {
            fprintf(outptr, "   ");
            dayCounter++;
        }
    
        /* print days of month */
        for(i = 1; i <= numDays[current]; i++)
        {
            dayCounter++;
            /* insert a newline for the last day of the week
               unless it is also the last day of the month  
            */
            if(dayCounter == 7 && i != numDays[current])
            {
                dayCounter = 0;
                fprintf(outptr, "%2d\n", i);
            }
            else
                fprintf(outptr, "%2d ", i);
        }
        fprintf(outptr, "\n\n");
    }

    fclose(outptr);
}

/****************************************************************
      function: printHeader
         input: char* to month name
        output: none
       purpose: prints centered month name and days of week
****************************************************************/
void printHeader(int m, FILE* outptr)
{
    char* month[] = {"January", "February", "March", "April", 
                     "May", "June", "July", "August", "September", 
                     "October", "November", "December "};

    char* day[] = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};
    int i;
    int length = strlen(month[m]);

    /* use calendar width of 20   */
    for(i = 0; i <= ((20 - length) / 2); i++)
        fprintf(outptr, " ");
    fprintf(outptr, "%s\n", month[m]);

    for(i = 0; i < 7; i++)
        fprintf(outptr, "%s ", day[i]);
    fprintf(outptr, "\n");
    
}

/****************************************************************
      function: calcDay
         input: int representing month (0-11 range)
        output: int representing the day of the week a month
                begins on

         notes: function is hard-coded for 2008
****************************************************************/
int calcDay(int m)
{
    /*  number of days in each month for 2008  */
    int numDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i;
    int start = 2;  /*  corresponds to Tuesday, which 2008 begins on  */
    int total = start;

    for(i = 0; i < m; i++)
        total += numDays[i];

    return (total % 7);
}

/***********************************************************
***                         Output                       ***

       January
Su Mo Tu We Th Fr Sa 
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31 

       February
Su Mo Tu We Th Fr Sa 
                1  2
 3  4  5  6  7  8  9
10 11 12 13 14 15 16
17 18 19 20 21 22 23
24 25 26 27 28 29 

        March
Su Mo Tu We Th Fr Sa 
                   1
 2  3  4  5  6  7  8
 9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30 31 

        April
Su Mo Tu We Th Fr Sa 
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 

         May
Su Mo Tu We Th Fr Sa 
             1  2  3
 4  5  6  7  8  9 10
11 12 13 14 15 16 17
18 19 20 21 22 23 24
25 26 27 28 29 30 31


         June
Su Mo Tu We Th Fr Sa 
 1  2  3  4  5  6  7
 8  9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30 

         July
Su Mo Tu We Th Fr Sa 
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31 

        August
Su Mo Tu We Th Fr Sa 
                1  2
 3  4  5  6  7  8  9
10 11 12 13 14 15 16
17 18 19 20 21 22 23
24 25 26 27 28 29 30
31 

      September
Su Mo Tu We Th Fr Sa 
    1  2  3  4  5  6
 7  8  9 10 11 12 13
14 15 16 17 18 19 20
21 22 23 24 25 26 27
28 29 30 

       October
Su Mo Tu We Th Fr Sa 
          1  2  3  4
 5  6  7  8  9 10 11
12 13 14 15 16 17 18
19 20 21 22 23 24 25
26 27 28 29 30 31 

       November
Su Mo Tu We Th Fr Sa 
                   1
 2  3  4  5  6  7  8
 9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30 

      December 
Su Mo Tu We Th Fr Sa 
    1  2  3  4  5  6
 7  8  9 10 11 12 13
14 15 16 17 18 19 20
21 22 23 24 25 26 27
28 29 30 31 

*/
