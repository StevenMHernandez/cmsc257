/*
       name:  Preetam Ghosh

       date:  March 11, 2008

    purpose:  demonstrate the use of the Standard C library

    problem:  We wish to open the file how_to_design_programs.txt
              and print out the lines containing the letters 
              forming the word program.  This means that lines 
              containing the words program, programming, programs,
              and so forth will be printed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char bufferArray[100];
    char word[] = "program";
    char *strptr;
    FILE *inptr;

    if ( (inptr = fopen("how_to_design_programs.txt", "r" )) == NULL )
    {
        printf("this file could not be opened for reading\n");
        exit(1);  /* we should exit if there is an error */
    }

    while( fgets(bufferArray, 100, inptr) != NULL )
    {
        /* the Standard C library function strstr has the form
               strstr(str1, str2)
           It returns a pointer to the location in str1 where
           str2 begins if it is there.  If not, it returns NULL.
        */
        strptr = strstr(bufferArray, word);
        if (strptr != NULL)
            printf(bufferArray);
    }

    fclose( inptr );
}

/****************************************************************

Many professions require some form of computer programming. 
Accountants program spreadsheets and word processors;
photographers program photo editors; musicians program synthesizers;
and professional programmers instruct plain computers. Programming
Yet programming is more than just a vocational skill. Indeed, good
programming is a fun activity, a creative outlet, and a way to
express abstract ideas in a tangible form. And designing programs
We therefore believe that the study of program design deserves
design programs.  On one hand, program design teaches the same
with programs is an active approach to learning. Interacting with
programs produces useful and fun things, which vastly increases
mathematics. On the other hand, program design teaches the same
programming tasks are formulated as word problems. Without critical
reading skills, a student cannot design programs that match the
specification. Conversely, good program design methods force a
student to articulate thoughts about programs in proper English.
This book is the first book on programming as the core subject of
it deemphasizes the study of programming language details,
or ``make the program structural.'' We have instead developed
second innovation is a radically new programming environment. In
the past, texts on programming ignored the role of the programming
provides a programming environment for beginners. It also grows
of programming tasks: large-scale programming as well as scripting.
Our guidelines are formulated as a number of program design recipes.
A design recipe guides a beginning programmer through the entire
students derive the programs with a checklist. Figure 1 shows the
   2.  the informal specification of a program's behavior; 
   4.  the development of a program template or layout; 

*/
