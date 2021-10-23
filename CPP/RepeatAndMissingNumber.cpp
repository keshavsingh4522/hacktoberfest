#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *nums = new int[n];
    for(int i = 0; i < n; ++i)
        cin>>nums[i];
    cout<<"REPEATED: "; 
    for(int i = 0; i < n; ++i)
    {
        if(nums[abs(nums[i]) - 1] < 0)
            cout<<abs(nums[i])<<' ';
        else
            nums[abs(nums[i]) - 1] *= -1;
    }
    cout<<endl;
    for(int i = 0; i < n; ++i)
        if(nums[i] > 0)
            cout<<"MISSING: "<<i+1;
    delete [] nums;
}
