#include <stdio.h>

struct person
{
    char name[20];
    int age;
    double weight;
};

int main(void)
{
    struct person John = {"John Smith", 25, 170.5};
    struct person Mary = {"Mary Jones", 32, 120};

    printf("%s weighs %5.1f pounds.\n", John.name, John.weight);

    printf("%s is %d years old.\n", Mary.name, Mary.age);
    Mary.age += 1;
    printf("On her next birthday, she will be %d years old.\n", Mary.age);
}

/*******************************************************
***                    Output                        ***

John Smith weighs 170.5 pounds.
Mary Jones is 32 years old.
On her next birthday, she will be 33 years old.

*/
