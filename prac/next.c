#include <stdio.h>

int main()
{
    float num_1, num_2;
    char op;

    printf("Please enter 1st number:\n");
    scanf("%f", &num_1);

    printf("Please enter 2nd number:\n");
    scanf("%f", &num_2);

    printf("Please enter your operator (+, -, *, /): ");
    scanf(" %c", &op);   // space is important

    switch (op)
    {
        case '+':
            printf("Result: %.3f\n", num_1 + num_2);
            break;

        case '-':
            printf("Result: %.3f\n", num_1 - num_2);
            break;

        case '*':
            printf("Result: %.3f\n", num_1 * num_2);
            break;

        case '/':
            if (num_2 != 0)
                printf("Result: %.3f\n", num_1 / num_2);
            else
                printf("Error: Division by zero not possible\n");
            break;

        default:
            printf("Invalid operator!\n");
    }

    return 0;
}