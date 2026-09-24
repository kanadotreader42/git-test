#include <stdio.h>
#include <math.h>

int add = 1;
int age = 15;
char name[50];

int main(void)
{
    printf("Please enter your age: ");
    scanf("%d", &age);

    while (age < 18)
    {
        age = age + add;
        printf("Current age is in-sufficient please try next year when you %d.\n", age);
    }
    
    return 0;
}