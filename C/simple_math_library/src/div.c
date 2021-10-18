#include <simplemath.h>
int divide(int first, int second)
{
    if (second == 0)
    {
        printf("divide by zero exception!");
        return -1;
    }
    return first / second;
}