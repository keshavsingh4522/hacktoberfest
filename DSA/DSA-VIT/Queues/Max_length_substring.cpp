#include <bits/stdc++.h>
using namespace std;
int main() {
    char arr[]="abcdafrtghh";
    int n=strlen(arr);
    int curr_len=0;
    int max_len=0;

    //sliding window
    int visited[1000];

    for(int i=0;i<n;i++)
    visited[i]=0;

    //for 1st character
    visited[arr[0]]=0;

    //for the remaining characters
    for(int i=1;i<n;i++)
    {
        int last=visited[arr[i]];

        //expansion
        if(last==-1 || (i-curr_len)>last)
        curr_len++;

        //expansion and contraction
        else
        {
            if(curr_len<max_len)
            max_len=curr_len;
            curr_len=i-last;
        }
        visited[arr[i]]=i;
    }
    if(curr_len<max_len)
    max_len=curr_len;
    cout<<max_len<<endl;
}
