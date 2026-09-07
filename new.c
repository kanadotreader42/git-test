#include <stdio.h>

int main(void)
{
    double kilograms;

    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);

    printf("%.2f kilograms = %.2f pounds\n", kilograms, kilograms * 2.20462);

    return 0;
}