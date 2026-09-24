#include <stdio.h>

int main()
{
    float mark_maths,mark_science,mark_english,mark_hindi,mark_ip,percent;
    char name[50];
    printf("Enter a  Name: ");
    scanf("%s", &name);
    printf("Enter the marks for maths: ");
    scanf("%f", &mark_maths);
    printf("Enter the marks for science: ");
    scanf("%f", &mark_science);
    printf("Enter the marks for english: ");
    scanf("%f", &mark_english);
    printf("Enter the marks for hindi: ");
    scanf("%f", &mark_hindi);
    printf("Enter the marks for ip: ");
    scanf("%f", &mark_ip);

    percent = ((mark_science+mark_maths+mark_english+mark_hindi+mark_ip)/500 ) *100;

    printf("Percentage : %f\n", percent);

   if (percent < 33)
{
    printf("Grade : F\n");
}
else if (percent <= 50)
{
    printf("Grade : D\n");
}
else if (percent <= 70)
{
    printf("Grade : C\n");
}
else if (percent <= 80)
{
    printf("Grade : B\n");
}
else if (percent <= 90)
{
    printf("Grade : A\n");
}
else
{
    printf("Grade : A+\n");
}
    
  return 0;
}