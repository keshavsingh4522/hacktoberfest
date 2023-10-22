#include <stdio.h>

int main() {
    int n, reversed_n = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Reverse the number
    while (n != 0) {
        reversed_n = reversed_n * 10 + n % 10;
        n /= 10;
    }

    printf("The reversed number is: %d", reversed_n);
    return 0;
}
