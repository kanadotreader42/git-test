#include <stdio.h>

int main()
{
    float celsius, fahrenheit;

    printf("Please enter celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (9.00 / 5.00) * celsius + 32;

    printf("The temp in fahranheit: %.2f", fahrenheit);

    return 0;
}
