#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int no,ans=0;


    for(int i=0;i<n;i++)
    {
        cin>>no;
        
        //XOR operation
        ans=ans^no;
    }

    cout<<ans;
}
