#include<stdio.h>

void quick_sort(int a[100],int p, int q)
{
    int j;

    if(p<q)
    {
        j=partition(a,p,q+1);

        quick_sort(a,p,j-1);

        quick_sort(a,j+1,q);
    }
}

int partition(int a[100], int p, int q)
{
    int t,i,j;
    t=a[p];
    i=p;
    j=q;

    do
    {
        do
        {
            i=i+1;
        } while (a[i]<t);
        do
        {
            j=j-1;
        } while (a[j]>t);
        if(i<j)
            interchange(a,i,j);
    } while (i<j);
    a[p]=a[j];
    a[j]=t;

    return j;
}

void interchange(int a[100], int i, int j)
{
    int t;

    t=a[i];
    a[i]=a[j];
    a[j]=t;
}

int main()
{
    int a[100],n,i;

    printf("Enter size of array : ");
    scanf("%d",&n);

    printf("Enter elements of array : ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    a[n+1]=9999;
    quick_sort(a,1,n);
    printf("Sorted array : ");
    for(i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}