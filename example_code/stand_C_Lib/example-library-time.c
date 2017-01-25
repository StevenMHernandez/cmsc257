/*
       name:  Preetam Ghosh
       date:  March 12, 2008

    purpose:  demonstrate the use of the Standard C library
*/

#include <stdio.h>
#include <time.h>

int main( void )
{
    time_t t1;
    char * t2;  /* pointer to converted time string */

    time(&t1);
    t2 = ctime(&t1);  /* convert the time to something meaningful */

    printf("%d\n\n", t1);  /* print the original value from time()  */
    printf("%s\n", t2);  /* print the time in a meaningful form   */
}


/****************************************************************

1205346948

Wed Mar 12 13:35:48 2008

*/
