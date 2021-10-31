#include<bits/stdc++.h>
using namespace std;

int main(){

    pair<int,string> p;
    cin>>p.first>>p.second;
    cout<<p.first<<" "<<p.second<<"\n";

    pair<int,string> &p1 = p;
    p1.first = 21;
    cout<<p.first<<" "<<p.second<<"\n"; 

    //pairs of array
    pair <int,int> p_arr[3]; //the size is 3
    p_arr[0] = {1,2};        
    p_arr[1] = {2,3};
    p_arr[2] = {3,4};
    for(int i=0;i<3;++i)
    {
        cout<<p_arr[i].first<<" "<<p_arr[i].second<<"\n";
    }
    return 0;
}