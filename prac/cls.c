#include<stdio.h>

int main(void){

char name[14];

printf("Please enter yout name: ");
fgets(name, sizeof(name), stdin);

printf("%s\n", name);
printf("Size of char: %d", sizeof(name));

return 0;
}