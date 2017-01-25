#include <stdio.h>

struct person
{
    char name[20];
    int age;
};

void doubleAge(struct person *);

int main(void)
{
    struct person John = {"John Smith", 25};

    doubleAge(&John);  /* we must pass the address
                          of John to the function */

    printf("John's age is now %d\n", John.age);
}

void doubleAge(struct person *somebody)
{
    somebody->age *= 2;
}

/*******************************************************
***                    Output                        ***

John's age is now 50

*/
