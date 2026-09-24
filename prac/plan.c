#include <stdio.h>

/*
 * Boilerplate C program
 * - Keep input, processing, and output as separate steps.
 * - This structure is easy to scale for bigger problems.
 */
int main(void)
{
    /* 1) Input variables */
    int a = 0;
    int b = 0;

    /* 2) Output variable */
    int sum = 0;

    /* 3) Input */
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    /* 4) Processing */
    sum = a + b;

    /* 5) Output */
    printf("Sum = %d\n", sum);

    return 0;
}
