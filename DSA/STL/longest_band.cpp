// T(n)=O(nlogn)

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     int a[n];

//     for(int i=0;i<n;i++)
//     cin>>a[i];

//     int largest=0;
//     sort(a,a+n);
//     for(int i=1;i<n-1;i++)
//     {
//         if((a[i]-a[i-1])==1)
//         largest++;
//         else
//         break;
//     }
//     cout<<largest+1;

// }


// better approach by using unordered set i.e. T(n)=O(n)