#ifndef SIMPLE_MATH_HEADER
#define SIMPLE_MATH_HEADER
#include <stdio.h>
#include <stdlib.h>
// returns absolute value, if you pass -1 will return 1 and 1 will be returned as 1.
int abs(int);
// add both the number a return the sum of both.
int add(int, int);
// substract first from second, and return the result as int.
int sub(int first, int second);
// multiply the both integers and return values.
int multiply(int, int);
// divide first with second parameter.
// Divide by zero is handled.
int divide(int, int);
// even: return 1 if int is divisble by 2 else 0
int even(int);
// odd
int odd(int);
// square = int * int
int square(int);
//half int / 2
int half(int);
#endif