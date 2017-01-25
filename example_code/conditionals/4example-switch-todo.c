/*
    author: Preetam Ghosh

      date: Fri Jan 18 14:20:46 CST 2008

   purpose: Demonstrate the use of the switch statement for generating a to-do list
*/

#include <stdio.h>

int main( void )
{
    int task = 3;  /* number of my current task */

    /* generate list of all remaining items */
    printf("your remaining tasks are\n");
    printf("-------------------------\n");
    switch(task)
    {
        case 4: printf("prepare lecture 3\n");
        case 2: printf("do homework #1\n");
        case 3: printf("study for class\n");
        case 5: printf("read chapter 1\n");
        case 1: printf("buy groceries\n");
    }


    /* what is next on my list? */
    printf("\n\nyour next task is\n");
    printf("-------------------------\n");
    switch(task)
    {
        case 4: printf("prepare lecture 3\n"); break;
        case 2: printf("do homework #1\n"); break;
        case 3: printf("study for class\n"); break;
        case 5: printf("read chapter 1\n"); 
                break;
        case 1: printf("buy groceries\n"); break;
    }
}

/*
   the output for this program is


your remaining tasks are
-------------------------
study for class
read chapter 1
buy groceries


your next task is
-------------------------
study for class

*/
