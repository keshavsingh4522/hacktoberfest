/*

Input: 4

Output:
00 01 02 03
11 12 13 04
10 15 14 05
09 08 07 06
*/


#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n][n];
    int l=0,r=n-1,u=0,b=n-1,val=0;
    while(l<r && u<b){
        for(int i=l;i<=r;i++)  {
            arr[u][i]=val++;
        } u++; 
        for(int i=u;i<=b;i++)  {
            arr[i][r]=val++;
        }r--;
        for(int i=r;i>=l;i--)  {
            arr[b][i]=val++;
        }b--;
        for(int i=b;i>=u;i--)  {
            arr[i][l]=val++;
        }l++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%02d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
