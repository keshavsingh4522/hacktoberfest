#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int i,j,k,l,m;
    for(i=1;i<=5;i++)
    {
        for(j=5;j>=i;j--)
            printf("");
        for(k=1;k<=i;k++)
            printf("*");
        for(l=1;l<=i;l++)
            printf("*");
        for(m=4;m>=i;m--)
            printf("");
        for(k=1;k<=i;k++)
            printf("");
        for(l=1;l<=i;l++)
            printf("*");
        printf("/n");
    }
    for(i=10;i>=1;i--)
    {
        for(j=10;j>=i;j--)
            printf("");
        for(l=1;l<=i;l++)
            printf("*");
        for (m=i;m>=2;m--)
            printf("*");
        printf("\n");
    }
    printf("\n---------LOVE---------");
    return 0;
}
