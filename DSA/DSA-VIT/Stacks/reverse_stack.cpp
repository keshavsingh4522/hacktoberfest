#include <bits/stdc++.h>
using namespace std;

void transfer(stack<int>&s1,stack<int>&s2,int n)
{
    //int n=s1.size();
    for(int i=0;i<n;i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}

void reverse(stack<int>&s1)
{
    stack<int>s2;
    int n=s1.size();
    for(int i=0;i<n;i++)
    {
        //remove top element of s1 and store it in another variable
        int x=s1.top();
        s1.pop();

        //transfer n-i-1 elements into s2 repeatedly while adding top to x
        transfer(s1,s2,n-i-1);
        s1.push(x);
        transfer(s2,s1,n-i-1);
    }
}

int main() {
   stack<int>s1;
    //int n=s1.size();

   for(int i=0;i<5;i++)
   s1.push(i);

//     cout<<"original stack:";
//     cout<<"\n";
//    while(!s1.empty())
//    {
//        cout<<s1.top()<<endl;
//        s1.pop();
//    }

//    cout<<"\n";
   reverse(s1);

   cout<<"reversed stack:";
    cout<<"\n";
   while(!s1.empty())
   {
       cout<<s1.top()<<endl;
       s1.pop();
   }

}

