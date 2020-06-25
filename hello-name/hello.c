#include <stdio.h>

int main(void)
{
  char *my_name = NULL;
  printf("Enter your name: ");
  scanf("%s", my_name);
  printf("Hello, %s\n", my_name);
}
