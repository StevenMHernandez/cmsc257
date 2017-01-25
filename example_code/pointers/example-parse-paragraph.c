/*
     author:  Preetam Ghosh
       date:  Sun Mar  2 17:59:48 CST 2008
    purpose:  separate a paragraph into individual sentences
 assumption:  each sentence ends with a period and there are one or more spaces
              between sentences

 pseudocode:  set pointer to first sentence
              for each character
                if it is a period
                  skip spaces until beginning of next sentence
                  set pointer to sentence
                  set last space to null character
              continue until all characters have been processed
              print strings corresponding to each pointer

 how it works: The text is a single string terminated by a null character.
               Each sentence is found and a pointer to the first character
               of the sentence is set.  At this time the space before the 
               current sentence is changed to a null character so that
               each sentence can be printed individually.
*/

#include <stdio.h>

int main(void)
{
    int i = 0;
    int counter = 0;

    char *sentence[16];  /* pointers to each sentence */

    /*  The following text is from 

        How to Design Programs: An Introduction to Computing and Programming 
        by Felleisen et al. 
        online at http://www.htdp.org/2003-09-26/Book/curriculum-Z-H-2.html

        Note that to get the text to appear correctly online, newlines were
        added to each end.  These should be removed before trying to run
        the program.
    */
	char text[] = "Many professions require some form of computer
                   programming. Accountants program spreadsheets and word
                   processors; photographers program photo editors; musicians
                   program synthesizers; and professional programmers instruct
                   plain computers. Programming has become a required
                   skill.  Yet programming is more than just a vocational
                   skill. Indeed, good programming is a fun activity, a
                   creative outlet, and a way to express abstract ideas in
                   a tangible form. And designing programs teaches a variety
                   of skills that are important in all kinds of professions:
                   critical reading, analytical thinking, creative synthesis,
                   and attention to detail.  We therefore believe that the
                   study of program design deserves the same central role
                   in general education as mathematics and English. Or,
                   put more succinctly, everyone should learn how to
                   design programs.  On one hand, program design teaches
                   the same analytical skills as mathematics. But, unlike
                   mathematics, working with programs is an active approach
                   to learning. Interacting with software provides immediate
                   feedback and thus leads to exploration, experimentation,
                   and self-evaluation. Furthermore, designing programs
                   produces useful and fun things, which vastly increases the
                   sense of accomplishment when compared to drill exercises in
                   mathematics. On the other hand, program design teaches the
                   same analytical reading and writing skills as English. Even
                   the smallest programming tasks are formulated as word
                   problems. Without critical reading skills, a student cannot
                   design programs that match the specification. Conversely,
                   good program design methods force a student to articulate
                   thoughts about programs in proper English.";

    sentence[counter] = text;

    /* keep going until the end of the paragraph is reached     */
    while(text[i] != '\0')  
    {
        if(text[i] == '.')
        {
            i++;  /* increase the index so that we are working with
                     the character after the period.               */
            while(text[i] == ' ')
            {
                /* there are one or more spaces between sentences,
                   so we need to skip over all of them to get the
                   beginning of the next sentence.                 */
                i++;
            }
            /* the last period may have been the end of the paragraph,
               so check for this                                       */
            if(text[i] != '\0') 
            {
                text[i - 1] = '\0'; /* terminate the previous sentence */
                counter++;
                sentence[counter] = &text[i];
            }
        }

        i++;
    }

    for(i = 0; i < 16; i++)
        printf("sentence %d: %s\n\n", i+1, sentence[i]);
}


/*************************************************
****************   Output   **********************

sentence 1: Many professions require some form of computer programming.

sentence 2: Accountants program spreadsheets and word processors; photographers program photo editors; musicians program synthesizers; and professional programmers instruct plain computers.

sentence 3: Programming has become a required skill. 

sentence 4: Yet programming is more than just a vocational skill.

sentence 5: Indeed, good programming is a fun activity, a creative outlet, and a way to express abstract ideas in a tangible form.

sentence 6: And designing programs teaches a variety of skills that are important in all kinds of professions: critical reading, analytical thinking, creative synthesis, and attention to detail. 

sentence 7: We therefore believe that the study of program design deserves the same central role in general education as mathematics and English.

sentence 8: Or, put more succinctly, everyone should learn how to design programs. 

sentence 9: On one hand, program design teaches the same analytical skills as mathematics.

sentence 10: But, unlike mathematics, working with programs is an active approach to learning.

sentence 11: Interacting with software provides immediate feedback and thus leads to exploration, experimentation, and self-evaluation.

sentence 12: Furthermore, designing programs produces useful and fun things, which vastly increases the sense of accomplishment when compared to drill exercises in mathematics.

sentence 13: On the other hand, program design teaches the same analytical reading and writing skills as English.

sentence 14: Even the smallest programming tasks are formulated as word problems.

sentence 15: Without critical reading skills, a student cannot design programs that match the specification.

sentence 16: Conversely, good program design methods force a student to articulate thoughts about programs in proper English.

*/
