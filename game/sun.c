#include <stdio.h>

int main(void)
{
    // Write your logic here
    FILE *pfile = fopen("C:\\Users\\ASUS\\Desktop\\world.txt", "r");

    if (pfile != NULL)
    {
        /* code */
        char ch;
        printf("File Opened Succesfully!\n");
        while ((ch = fgetc(pfile)) != EOF)
        {
            putchar(ch);
        }
        
        fclose(pfile);
    }
    else
    {
        printf("Could not open the File!\n");
    }
    return 0;
}