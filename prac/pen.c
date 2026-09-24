#include <stdio.h>

int main()
{
    int age;
    printf("Please enter your age: ");
    if (scanf("%d", &age) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }

    if (age < 10)
    {
        printf("The age is less than 10.\n");
    }
    else if (age == 10)
    {
        printf("The age is exactly 10.\n");
    }
    else
    {
        printf("The age is more than 10.\n");
    }

    return 0;
}
