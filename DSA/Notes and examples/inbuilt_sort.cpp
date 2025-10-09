#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    int a[]={10,2,4,5};
    cout<<"given array:"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<a[i]<<endl;
    }

    sort(a,a+4);
    cout<<"sorted array:"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<a[i]<<endl;
    }
}

