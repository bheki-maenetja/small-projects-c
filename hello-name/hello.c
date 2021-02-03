#include <stdio.h>

int main(void)
{
    char my_name[100];
    printf("Please enter your name: ");
    // scanf("%s", my_name);
    fgets(my_name, 100, stdin);
    printf("Hello, %s\n", my_name);
}
