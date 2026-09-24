#include <stdio.h>

int main()
{
    float principal, rate, time, simple_interest;

    printf("Please enter the principal amount: ");
    scanf("%f", &principal);
    printf("Please enter the interest rate: ");
    scanf("%f", &rate);
    printf("Please enter the time: ");
    scanf("%f", &time);

    simple_interest = (principal * rate * time) / 100;

    printf("The simple interest is: %.2f", simple_interest);

    return 0;
}
