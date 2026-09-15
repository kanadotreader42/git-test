#include <stdio.h>

int main(void)
{
    // Keypad layout as a 2D character array (4 rows x 3 columns)
    char numpad[][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}};

    // Calculate dimensions automatically
    int rows = sizeof(numpad) / sizeof(numpad[0]);
    int cols = sizeof(numpad[0]) / sizeof(numpad[0][0]);

    // Print keypad row by row
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c ", numpad[i][j]);
        }
        printf("\n");
    }

    return 0;
}
