#include <stdio.h>

void capitalize(char [], int);

int main (void)
{
    char text[] = "TEACHING ASSEMBLY LANGUAGE WITHOUT USING (AS MUCH) ASSEMBLY LANGUAGE";
    int stringsize;

    stringsize = sizeof(text)/sizeof(char);
    capitalize(text, stringsize);

    printf("%s\n", text);
}

void capitalize(char input[], int size)
{
    int i;
    int sawSpace = 0;

    for(i = 1; i < size - 1; i++)
        if(input[i] == ' ')
            sawSpace = 1;
        else if(input[i] >= 65 && input[i] <= 90)
        {
            if(sawSpace == 1)
            {
                sawSpace = 0;
                continue;
            }
            else
                input[i] += 32;
        }
}

/*
Teaching Assembly Language Without Using (As Much) Assembly Language
*/

