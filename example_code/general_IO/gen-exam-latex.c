/*
      author:  Preetam Ghosh
        date:  March 29, 2008
     purpose:  Create a LaTeX file for the first 15 exam problems.

  pseudocode:  open a file for writing the output
               for each of the exam programs
                   open the file for reading
                   write the LaTeX formatting commands
                   write the exam program source code
                   write the remaining LaTeX formatting commands
                   close the exam program
               close the output file

      format: here is an example of the output for the first program

	%q01
	\item What does the following program print?
	\begin{verbatim}
    #include <stdio.h>
    
    int main( void )
    {
        int i;
        char *text[] = {"Dogs", "are", "really", "inside", "neurotics."};
    
        for(i = 0; i < 5; i++)
            printf("%c", *(*(text + i) + 0) );
    }
	\end{verbatim}
	\vspace{\baselineskip}
	\vspace{\baselineskip}
	\vspace{\baselineskip}
	\vspace{\baselineskip}
	\vspace{\baselineskip}
	\vspace{\baselineskip}
	\vspace{\baselineskip}
	\vspace{\baselineskip}

*******************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char filename[30];
    char input[100];

    FILE *inptr;
    FILE *outptr;

    char qnum[20];
    char spaces[] = "    ";
    char qstring[] = "\t\\item What does the following program print?\n";
    char bverb[] = "\t\\begin{verbatim}\n";
    char everb[] = "\t\\end{verbatim}\n";
    char skip[] = "\t\\vspace{\\baselineskip}\n";

    int i, j;
    int num, exam_num;

    if ( argc != 3 )
    {
        printf("usage: gen-exam-latex exam# #files\n");
        exit(1);
    }

    exam_num = atoi(argv[1]);
    num = atoi(argv[2]);

    if ( (outptr = fopen("exam-programs.tex", "w" )) == NULL )
    {
        printf("this file could not be opened for writing\n");
        exit(1);  /* we should exit if there is an error */
    }

    /* loop through the programs */
    for(i = 1; i <= num; i++)
    {
        /* sprintf() prints to a character array and has the 
           following format:

           sprintf( character array, formatted string, 
                    value to use in formatted string )

           here, the name of the character array is filename. 
           sprintf() is used to create the name of the file to 
           read.  the filenames are test1-q01.c, test1-q02.c, 
           and so forth, so the current value of i in the for 
           loop is used in the formatted string.  */
        sprintf( filename, "test%d-q%02d.c", exam_num, i );
       
        if ( (inptr = fopen(filename, "r" )) == NULL )
        {
            printf("%s could not be opened for reading\n", filename);
            exit(1);  /* we should exit if there is an error */
        }
        sprintf( qnum, "\t%%q%02d\n", i);
        fputs(qnum, outptr);
        fputs(qstring, outptr);
        fputs(bverb, outptr);
    
        while( fgets(input, 100, inptr) != NULL )
        {
            fputs(spaces, outptr);
            fputs(input, outptr);
        }
    
        fputs(everb, outptr);
        for(j = 0; j < 8; j++)
            fputs(skip, outptr);

        fclose( inptr );
    }

    fclose( outptr );
}
