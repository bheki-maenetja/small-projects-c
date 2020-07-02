#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int upper_bound, lower_bound, user_num, rand_num;
  printf("Enter a lower bound: ");
  scanf("%d", &lower_bound);

  do
  {
    printf("Enter an upper bound: ");
    scanf("%d", &upper_bound);
  } while (upper_bound <= lower_bound);
  
  do
  {
    printf("Enter a number between %d and %d: ", lower_bound, upper_bound);
    scanf("%d", &user_num);
  } while (user_num > upper_bound || user_num < lower_bound);
  
  printf("You have chosen %d\n", user_num);
  rand_num = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
  
}