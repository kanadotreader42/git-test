#include <stdio.h>

int main() {
    int x = 0;
    int y;
    int add = 1;

    printf("Enter the target value (y): ");
    scanf("%d", &y);

    while (x < y) {
        x = x + add;   // keep adding
        printf("Current value of x: %d\n", x);
    }

    printf("Final value reached: %d\n", x);

    return 0;
}