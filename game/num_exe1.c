#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // Simple C quiz
    char question[][100] = {"What is the correct extension for a C source file?",
                             "Which keyword is used to create a loop in C?",
                             "Which symbol is used to end a statement in C?"};
    char option[][100] = {"A) .cpp\nB) .java\nC) .c\nD) .py",
                         "A) repeat\nB) for\nC) loop\nD) cycle",
                          "A) :\nB) .\nC) ,\nD) ;"};
    char answer[][10] = {"C", "B", "D"};
    char user_answer = '\0';
    int score = 0;

    for (int i = 0; i < 3; i++) // rows
    {
        printf("%s \n", question[i]);
        printf("%s \n", option[i]);
        printf("Please enter your answer: ");

        // Leading space before %c skips leftover whitespace/newline.
        scanf(" %c", &user_answer);
        user_answer = (char)toupper((unsigned char)user_answer);

        if (user_answer == answer[i][0])
        {
            printf("Correct!\n\n");
            score++;
        }
        else
        {
            printf("Wrong! Correct answer is %c\n\n", answer[i][0]);
        }
    }

    printf("Final Score: %d/3\n", score);

    return 0;
}
