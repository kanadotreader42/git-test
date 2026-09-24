#include <stdio.h>
#include <math.h>

int main()
{
    double principal, rate, time, interest, amount;
    int choice;

    printf("Interest Calculator\n");
    printf("1. Simple Interest\n");
    printf("2. Compound Interest\n");
    printf("Choose calculation type (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter principal amount: ");
    scanf("%lf", &principal);

    printf("Enter annual interest rate (in %%): ");
    scanf("%lf", &rate);

    printf("Enter time (in years): ");
    scanf("%lf", &time);

    if (choice == 1)
    {
        interest = (principal * rate * time) / 100.0;
        amount = principal + interest;
        printf("\nSimple Interest: %.2lf\n", interest);
        printf("Total Amount: %.2lf\n", amount);
    }
    else if (choice == 2)
    {
        amount = principal * pow(1 + rate / 100.0, time);
        interest = amount - principal;
        printf("\nCompound Interest: %.2lf\n", interest);
        printf("Total Amount: %.2lf\n", amount);
    }
    else
    {
        printf("\nInvalid choice. Please run the program again and choose 1 or 2.\n");
    }

    return 0;
}
