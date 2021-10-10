//To check given word is pallindrome or not

#include<bits/stdc++.h>
using namespace std;

int main()
{
    
int l;
cin>>l;

char arr[l+1];
cin>>arr;

int c=0;

for(int i=0;i<l/2;i++)
{
    if(arr[i]!=arr[l-1-i])
    {
        c++;
        break;
    }
}

if(c>0)
cout<<"number is not pallindrome";

else
cout<<"number is pallindrome";

return 0;
}
