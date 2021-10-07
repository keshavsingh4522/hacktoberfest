#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char a[100],b[100];
    cout<<"Enter the string: ";
    cin>>a;

    int i,n= strlen(a);
    for(i=0;i<n;i++)
    {
        b[n-1-i]=a[i];
    }

    if(strcmp(a,b)==0)
        cout<<"It is a palindrome";
    else
        cout<<"It is not a palindrome";
    return 0;
}
