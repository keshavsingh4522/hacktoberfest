//Encryption of string in Caesar cipher
#include<stdio.h>
#include<string.h>
#define max 100

int main() {
    int i, n, val;
    char string[max], temp;
    printf("\nEnter the string to encrypt: ");
    fgets(string, max, stdin);
    printf("\nEnter the key: ");
    scanf("%d", &n);
    printf("\nEncrypted string: ");
    for (i = 0; i < strlen(string)-1; i++) {
        val = string[i];
        //Find ASCII value, convert it to alphabet order
        //Add the key and convert it back to ASCII
        temp = ((val + n - 65) % 26) + 65;
        printf("%c", temp);
    }
    return 0;
}