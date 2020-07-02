#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int upper_bound, lower_bound, user_num;
  printf("Enter a lower bound: ");
  scanf("%d", &lower_bound);
  printf("Enter an upper bound: ");
  scanf("%d", &upper_bound);
  
  do
  {
    printf("Enter a number between %d and %d: ", lower_bound, upper_bound);
    scanf("%d", &user_num);
  } while (user_num > upper_bound || user_num < lower_bound);
  
  printf("You have chosen %d\n", user_num);
  // for (int i = 0; i < 5; i++)
  // {
  //   int rand_num = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
  //   printf("%d\n", rand_num);
  // }
}