#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool keep(int age);
void printUserInfo(char name[], int age);

int main(void)
{
    char name[50];
    int age = 0;

    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Please enter your age: ");
    if (scanf("%d", &age) != 1)
    {
        printf("Invalid age input.\n");
        return 1;
    }

    printUserInfo(name, age);
    bool old = keep(age);

    if (old == true)
    {
        printf("You may sign up.\n");
    }
    else
    {
        printf("You are not eligible.\n");
    }

    return 0;
}

bool keep(int age)
{
    if (age >= 18)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void printUserInfo(char name[], int age)
{
    printf("You are %s and you are %d years old.\n", name, age);
}
