/*BuBBle SorT*/ 
#include <stdio.h> 
int main()
{
    int a[10], t, n, j, i;
    printf("Enter the number of element you want to add: ");
    scanf("%d", &n);
    printf("\nEnter the elements:\n\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n - i - 1; j++)
        {

            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
