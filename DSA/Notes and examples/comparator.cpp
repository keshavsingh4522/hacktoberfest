#include <iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b)
{
    //sorts array in decreasing order
    return  a>b;
}

int main() {
    int a[]={10,2,4,5};
    cout<<"given array:"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<a[i]<<endl;
    }

    //adding function as parameter
    sort(a,a+4,compare);
    cout<<"sorted array:"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<a[i]<<endl;
    }
}

