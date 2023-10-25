#include <stdio.h>

int main() {
    int binaryNum = 101010; // Example binary number
    printf("The binary number is: %d\n", binaryNum);

    // Convert binary to decimal
    int decimalNum = 0;
    int base = 1;
    int temp = binaryNum;
    while (temp) {
        int lastDigit = temp % 10;
        temp = temp / 10;
        decimalNum += lastDigit * base;
        base = base * 2;
    }
    printf("The decimal equivalent is: %d\n", decimalNum);

    // Performing bitwise operations
    int a = 5; // 101 in binary
    int b = 3; // 011 in binary
    printf("Bitwise AND: %d\n", a & b); // Bitwise AND
    printf("Bitwise OR: %d\n", a | b); // Bitwise OR
    printf("Bitwise XOR: %d\n", a ^ b); // Bitwise XOR
    printf("Bitwise NOT of a: %d\n", ~a); // Bitwise NOT
    printf("Left shift of a by 1: %d\n", a << 1); // Left shift
    printf("Right shift of a by 1: %d\n", a >> 1); // Right shift

    return 0;
}
