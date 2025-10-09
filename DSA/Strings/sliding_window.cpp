#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int>a={1,3,2,1,4,1,3,2,1,1,2};
    int n=a.size();
    int sum=8;
    int i=0,j=0,cs=0;

    while(j<n)
    {

        //right expansion
        cs+=a[j];
        j++;

        //left contraction
        while(cs>sum and i<j)
        {
            cs-=a[i];
            i++;
        }

        if(cs==sum)
        cout<<i<<" "<<j-1<<endl;
    }
}
