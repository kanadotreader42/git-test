#include <stdio.h>

int main(void)
{
    // Write your logic here
    int numbers[] = {10, 20, 30, 40, 50};
    char name[] = "Kavya sharma";
    printf("%d\n", sizeof(numbers));
    printf("%d\n", sizeof(numbers[0]));

    int element = (sizeof(numbers) / sizeof(numbers[0]));
    
    printf("%d \n", element);

    for (int i = 0; i < element; i++)
    {
        printf("%c", name[i]);
    }
    return 0;
}