#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n, number, ind = -1;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int* arr = malloc(sizeof(int) * n);
    printf("Enter Array Elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the Number to be searched : ");
    scanf("%d", &number);
    for (int i = 0; i < n; i++)
    {
        if (number == arr[i])
        {
            ind = i;
            break;
        }
    }
    if (ind != -1)
    {
        printf("\nElement %d found at %d position", number, ind + 1);
    }
    else
    {
        printf("Element not found :)\n");
    }
    return 0;
}
