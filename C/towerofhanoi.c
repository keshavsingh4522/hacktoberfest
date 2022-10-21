#include<stdio.h>
void tower_of_Hanoi(int n,char from,char to,char aux)
{
    if(n==0)
    return ;
    else
    tower_of_Hanoi(n-1,from,aux,to);
    printf("%c to %c\n",from,to);
    tower_of_Hanoi(n-1,aux,to,from);
}
int main()
{
    int n;
    printf("Enter No. of Disks:");
    scanf("%d",&n);
    tower_of_Hanoi(n,'A','B','C');
    return 0;
}