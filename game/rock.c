#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getuserinput();
int getpcinput();
void getwinner(int user_choice, int userpc_input);

int main(void)
{
    // Write your logic here
    printf("*** Rock, paper and Scissor game! ***\n");
    int userpc_choice = getpcinput();
    int user_choice = getuserinput();

    switch (user_choice)
    {
    case 1:
        printf("You choose Rock!\n");
        break;
    case 2:
        printf("You choose Paper!\n");
        break;
    case 3:
        printf("You choose Scissor!\n");
        break;

    default:
        break;
    }
    switch (userpc_choice)
    {
    case 1:
        printf("PC choose Rock!\n");
        break;
    case 2:
        printf("PC choose Paper!\n");
        break;
    case 3:
        printf("PC choose Scissor!\n");
        break;

    default:
        break;
    }

    getwinner(user_choice, userpc_choice);
    return 0;
}

int getuserinput()
{
    int userchoice = 0;

    do
    {
        printf("This game of choice!\n");
        printf("1> for Rock!\n");
        printf("2> for Paper!\n");
        printf("3> for Scissor!\n");
        printf("Please enter your choice: ");
        scanf("%d", &userchoice);
    } while (userchoice < 1 || userchoice > 3);

    return userchoice;
}
int getpcinput()
{
    srand(time(NULL));

    int choice = (rand() % 3) + 1;

    return choice;
}
void getwinner(int user_choice, int userpc_input)
{
    if (user_choice == userpc_input)
    {
        printf("Its a Tie!\n");
    }
    else if (
        (user_choice == 1 && userpc_input == 3) ||
        (user_choice == 2 && userpc_input == 1) ||
        (user_choice == 3 && userpc_input == 2))
    {
        printf("You Win!\n");
    }
    else
    {
        printf("You Lose!\n");
    }
}
