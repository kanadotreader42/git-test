#include <stdio.h>
#include <stdbool.h>

float killa(int age)
{
    if (age >= 18)
        {
            printf("You can sign up.\n");
        }
    else
    {
        printf("You cannot sign up unntil you are 18+.\n");
    }
}

int main(void)
{
    int prin;

    printf("Please enter age: ");
    scanf("%d", &prin);

    int age = killa(prin);

    printf("%c", age);

    return 0;
}