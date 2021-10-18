#include "./include/simplemath.h"

int main()
{
    int a = 10, b = 20;
    int neg = -10;
    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("Number is even? : %s\n", even(3) ? "True" : "False");
    printf("Number is even? : %s\n", even(30) ? "True" : "False");
    printf("Number is Odd ? : %s\n", odd(3) ? "True" : "False");
    printf("Number is Odd ? : %s\n", odd(20) ? "True" : "False");
    printf("Square of %d = %d\n", a, square(a));
    printf("Half of %d = %d\n", a, half(a));
    printf("Absolute value of %d = %d\n", neg, abs(neg));
    return EXIT_SUCCESS;
}