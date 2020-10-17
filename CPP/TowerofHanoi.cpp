#include <iostream>

using namespace std;

void TowerofHanoi(int n,int a,int b,int c)
{
    if(n>0)
    {
        TowerofHanoi(n-1,a,c,b);
        cout<<"Move a disk from  "<<a<<" to "<<c<<endl;
        TowerofHanoi(n-1,b,a,c);
    }
}

int main()
{
    int n;//total no of Disks
    cin>>n;

    TowerofHanoi(n,1,2,3);//1 2 3 are the Rods placed
    return 0;
}
