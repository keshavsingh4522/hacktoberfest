#include<bits/stdc++.h>
using namespace std;
void rev_array(int a[5],int sizze)
{
    int low=0;
    int high=sizze-1;
    while(low<high)
    {
        if(low==high)
        break;
        swap(a[low],a[high]);
        low++;
        high--;
    }
    for (int i=0;i<=sizze;i++)
    cout <<a[i]<<endl;
}
int main()
{
    int abb[5]={1,2,3,4,5};
    int sizze=sizeof(abb)/sizeof(abb[0]);
    rev_array(abb,sizze);
    
}
