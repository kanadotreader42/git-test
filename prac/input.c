#include <stdio.h>

int main()
{
    float radius, volume, height;
    printf("Enter the radius: ");
    scanf("%f", &radius);
    printf("Enter the height: ");
    scanf("%f", &height);
    float pi = 22.00 / 7.00;

    volume = radius * radius * pi * height;
    printf("The Volume is: %.01f", volume);

    return 0;
}
