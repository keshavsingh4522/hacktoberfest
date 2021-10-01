//if the number is bigger than the numbers in right then its a leader;
 //1.figure out the biggest number in array ,the numbers before biggest 
//number cant be a leader 
//2.return the largest number and search for the biggest number to the right of the number.
     
#include<bits/stdc++.h>
using namespace std;

void leader(int a[],int n)
{
    int lead=a[n-1];
    cout<<lead<<endl;
    for(int i=n-2;i>0;i--)
    {
        if(a[i]>lead)
        {
            lead=a[i];
            cout<<lead<<endl;
        }
        
    }
} 
int main()
{
    int arr[10]={5,3,6,3,345,7,54,9,4,7};
    int n=10;
    leader(arr,n);
}        

  