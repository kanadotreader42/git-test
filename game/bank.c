#include <stdio.h>

void checkbalance(float balance);
float deposit();
float withdraw(float balance);

int main(void)
{
    // Banking Program

    printf("**This is a banking system!**");
    int choice = 0;
    float balance = 0.0f;

    do
    {
        printf("\nPlease choose an option: \n");
        printf("1> for Balance!\n");
        printf("2> for Deposit!\n");
        printf("3> for Withdraw!\n");
        printf("4> for Exit!\n");
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            checkbalance(balance);
            break;        
        case 2:
            balance = balance + deposit();
            break;        
        case 3:
            balance = balance - withdraw(balance);
            break;        
        case 4:
            printf("You have exited the program!\n");
            printf("Thank for using our services!\n");
            break;        
        default:
            printf("Invalid input!\n");
            break;
        }
    } while (choice != 4);
    
    return 0;
}
void checkbalance(float balance){
    printf("\n\nYour Current Balance is %f!\n", balance);
}
float deposit(){
    float amount = 0;
    printf("\n\nPlease enter amount to be deposited: ");
    scanf("%f", &amount);
    return amount;
}
float withdraw(float balance){
    float amount = 0;
    printf("\n\nPlease Enter Amount to Withdraw: ");
    scanf("%.2f", &amount);
    return amount;
}