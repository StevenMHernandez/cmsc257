#include <stdio.h>

struct person
{
    char name[20];
    int age;
};

struct person fill(void);

int main(void)
{
    struct person John;

    John = fill();
    printf("%s is %d years old.\n", John.name, John.age);
}

struct person fill(void)
{
    struct person somebody = {"John Smith", 25};
    return somebody;
}

/*******************************************************
***                    Output                        ***

John Smith is 25 years old.

*/
