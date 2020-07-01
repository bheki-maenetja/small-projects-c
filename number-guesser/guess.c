#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int upper_bound, lower_bound;
  upper_bound = 9;
  lower_bound = 4;
  for (int i = 0; i < 5; i++)
  {
    int rand_num = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
    printf("%d\n", rand_num);
  }
}