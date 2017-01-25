/*********************************************************
***         example-struct-unique-main.c              ***/

/*
      author:  Preetam Ghosh
        date:  April 9, 2008
     purpose:  Produce a list of unique names

  pseudocode:  read an array of structures containing company names
               for each company name
                   check if the name is on the unique_name list
                   if so
                       skip to the next company name
                   else
                       add the company name to the unique_name list
*/


#include <stdio.h>
#include "example-struct-unique.h"


int main(void)
{
    /* array to hold all names encountered */
    COMPANY names[MAX] = {{"Walmart"},
                          {"Best Buy"},
                          {"Walmart"},
                          {"Home Depot"},
                          {"Target"},
                          {"Home Depot"},
                          {"Target"},
                          {"Best Buy"},
                          {"Walmart"},
                          {"Home Depot"} };         

    COMPANY unique_names[MAX];  /* array in which each company name
                                   only appears once                   */
    int i;


    /* we need some way to know where we are in searching an
       array.  set the first character of each array element,
       which is a character array inside a structure, to null
       so that we know where the current end is of the list;
       new names will go to the end of the list  */
    for(i = 0; i < MAX; i++)
        unique_names[i].company[0] = '\0';

    /* loop throught names seen, picking out unique names */
    printf("Original List\n------------\n");
    for(i = 0; i < MAX; i++)
    {
        onList(names[i].company, unique_names);
        printf("%s\n", names[i].company);
    }

    printf("\nUnique Names\n------------\n");
    i = 0;
    while( unique_names[i].company[0] != '\0')
        {
            printf("%s\n", unique_names[i].company);
            i++;
        }
}
   

/*********************************************************
***       example-struct-unique-functions.c           ***/

#include <string.h>
#include "example-struct-unique.h"

void onList( char* word, COMPANY unique[] )
{
    int i = 0;
    enum bln match = F;

    if(unique[0].company[0] == '\0')  /* first time through list is empty */
        strcpy( unique[0].company, word );
    else
    {
        while( unique[i].company[0] != '\0')
        {
            if( strcmp(unique[i].company, word) == 0)
            {
                match = T;  /* found match*/
                break;
            }
            i++;
        }

        if (match == F)
            strcpy( unique[i].company, word );
    }
}


/*********************************************************
***             example-struct-unique.h               ***/
#define MAX 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***   enumerated types    ***/
enum bln {F, T};


/***   structures          ***/
typedef struct
{
    char company[20];
}
COMPANY;


/***      function declarations       ***/
void onList(char* word, COMPANY names[]);


/*********************************************************
***                        Output                      ***
Original List
------------
Walmart
Best Buy
Walmart
Home Depot
Target
Home Depot
Target
Best Buy
Walmart
Home Depot

Unique Names
------------
Walmart
Best Buy
Home Depot
Target

*/

