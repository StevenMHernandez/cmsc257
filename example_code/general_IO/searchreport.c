/*
  author:  Preetam Ghosh
    date:  April 15, 2008
    file:  searchreport.c

 purpose:  search report, looking for the word 'Total'
           get the value associated with total and sum
           all of the totals
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addCommas(char *, int);

int main(void)
{
    FILE *inptr;
    char buffer[100]; /* allocate space for a line */
    char *word;
    char *delimiter = " "; 
    int sum = 0;
    int value;
    char withCommas[15];

    if ( (inptr = fopen("report.txt", "r" )) == NULL )
    {
        printf("this file could not be opened for reading\n");
        exit(1);  /* we should exit if there is an error */
    }

    printf("The individual totals are:\n\n");
    /* read each line until the end of the file */
    while( fgets(buffer, 100, inptr) != NULL )
    {
        /* tokenize line */
        word = strtok(buffer, delimiter);
        if (strcmp(word, "Total") == 0 )
        {
            value = atoi( strtok( NULL, delimiter ) );
            sum += value;
            addCommas(withCommas, value);
            printf("%7s\n", withCommas);
        }
    }  

    addCommas(withCommas, sum);
    printf("\nThe overall total is %s.\n", withCommas);

    fclose( inptr );
}

/*
       name:  addCommas
      input:  pointer to character array, int
    purpose:  take an int and convert it to a string with
              commas every three digits to aid in reading
    example:  1234567  becomes  1,234,567
*/
void addCommas(char *str, int num)
{
    char numstr[20];
    int i;
    int rem, div3;
    int pad = 0;
    int precomma = -1;  /* start at -1 to include null */
    int strcount;
    int len;

    sprintf(numstr, "%d", num);
    div3 = (int)strlen(numstr)/3;
    rem = (int)strlen(numstr)%3;
    if(rem == 0)
        pad = 1;


    len = (int)strlen(numstr);
    strcount = len;
    /* we need to increase the total number of characters
       to include the commas
    */
    for(i = (len + div3 - pad); i >=0; i-- )
    {
        precomma++;

        if(precomma == 4)
        {
            str[i] = ',';
            precomma = 0;
        }
        else
        {
            str[i] = numstr[strcount];
            strcount--;
        }
    }
}

/***************************************************************
***                        Input                             ***

              WALMART

       August          11453
       January         39165
       May             33407
       December        39048
      -----------------------
       Total          123073


             BEST BUY

       February        39562
       August          39920
       December        29154
       September       35777
       January         33064
       July            11405
       March           17149
       June            29482
       October         22155
      -----------------------
       Total          257668


              TARGET

       July            32016
       January         20070
       May             38278
       November        13916
       February        18333
      -----------------------
       Total          122613


            HOME DEPOT

       October         28534
       August          25259
       June            32794
      -----------------------
       Total           86587


****************************************************************
***                        Output                            ***

The individual totals are:

123,073
257,668
122,613
 86,587

The overall total is 589,941

*/
