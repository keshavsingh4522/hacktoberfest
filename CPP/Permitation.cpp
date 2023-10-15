//author : saurabh nikam
//hackober fest submittion
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 #define ios  ios::sync_with_stdio(false);cin.tie(NULL)
 #define endl  "\n"
 #define ll long long  
 
 void solve()
 {
     ll n;
     cin>>n;
     if(n==1)
     {
         cout<<1<<endl;
     }else if(n==2||n==3){
         cout<<"NO SOLUTION"<<endl;
     }else if(n>3){
         vector <ll> arr;
         for(ll i=2;i<=n;i=i+2)
         {
             arr.push_back(i);
         }
         for(ll i=1;i<=n;i=i+2)
         {
             arr.push_back(i);
         }
         for(ll i=0;i<arr.size();i++)
         {
             cout<<arr[i]<<" ";
         }
         cout<<endl;
 
     }
 } 
int  main()
{
    ios;
    int tt; //
    tt=1;
    //cin>>tt;
 
    while(tt--)
    {
        solve();
    }
    return 0;
}