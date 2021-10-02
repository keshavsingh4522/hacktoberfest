#include <bits/stdc++.h>
using namespace std;

int count(int n, vector<int> a, int key)
{
    int freq=0;
    for(int i=0;i<n;i++)
    {
        if(key==a[i])
        {
            freq++;
            
        }
    }
    return freq;
}

int main() {
    vector<int>a={0,1,1,1,1,2,2,2,3,4,4,5,10};
    int n=a.size();
    int key=2;

    cout<<count(n,a,key);

}
