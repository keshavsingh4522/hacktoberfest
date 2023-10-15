#include <iostream>
using namespace std;
int main() {
    int n,i;
    cin>>n;

    //creating a dynamic array
    int *ptr=new int[10000];

    for(i=0;i<n;i++)
    cin>>ptr[i];

    for(i=0;i<n;i++)
    cout<<ptr[i]<<endl;

    //deleting memory
    delete [] ptr;
}

