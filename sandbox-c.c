#include <stdio.h>

int main()
{
    float a;
    float b;
    printf("Enter your first number: ");
    scanf("%f", &a);
    printf("\nEnter your second number: ");
    scanf("%f", &b);
    printf("a + b = %f\na - b = %f\na x b = %f\na ÷ b = %f\n", a+b, a-b, a*b, a/b);
}