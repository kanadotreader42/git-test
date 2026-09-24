#include <stdio.h>
#include <stdbool.h>

bool check(float age)
{
    if (age >= 18)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main(void)
{
    // Write your logic here
    float age = check(2);

    if (age == true)
    {
        printf("You can sign up.\n");
    }
    else
    {
        printf("You can only sign if you are above 18+.\n");
    }

    return 0;
}