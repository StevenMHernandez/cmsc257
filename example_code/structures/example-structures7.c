#include <stdio.h>

struct person
{
    char name[20];
    int age;
};

int doubleAge(struct person);

int main(void)
{
    struct person John = {"John Smith", 25};
    int newage;

    newage = doubleAge(John);
    printf("the new age is %d\n", newage);
}

int doubleAge(struct person somebody)
{
    return somebody.age * 2;
}

/*********************************************
***               Output                   ***

the new age is 50

*/
