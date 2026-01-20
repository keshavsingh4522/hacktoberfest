#include <stdio.h>

int main() {
    char stringWithComma[] = "1,000,000.00";
    float number;
    
    sscanf(stringWithComma, "%f", &number);
    
    printf("%.2f\n", number); // Output: 1000000.00
    
    return 0;
}
