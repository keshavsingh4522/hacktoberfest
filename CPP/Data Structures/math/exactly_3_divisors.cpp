// // { Driver Code Starts
// //Initial Template for C++
// #include <bits/stdc++.h>
// using namespace std;
//  // } Driver Code Ends
// //User function Template for C++
// class Solution{
//     public:
//     void exactly3Divisors(int n)
//     {
//         vector<int>prime;
//         for(int i=0;i<=n;i++)
//         {
//             prime.push_back(1);
//         }
//         prime[0]=0;
//         prime[1]=0;
//         for(int i=2;i<=sqrt(n);i++)
//         {
//             for(int j=2;j*i<=n;j++)
//             {
//                 prime[i*j]=0;
//             }
//         }
//         vector<int>final_prime;
//         for(int i=0;i<=n;i++)
//         {
//             if(prime[i]==1)
//             {
//                 final_prime.push_back(i);
//             }
//         }
//         //cout<<"size of final:   "<<final_prime.size()<<endl;
//         for(int i=0;i<=final_prime.size();i++)
//         {
//             int x=(pow(final_prime[i],2));
//             final_prime[i]=pow(final_prime[i],2);
         
//         }
//         int count=0;
//         for(auto i:final_prime)
//         {
//             if(i<=n)
//             cout<< i<<" has only 3 divisor"<<endl;; 
//             count++;=
//         } 
//         cout<<"totally "<<count<<"numbers has 3 divisors";

//     }
     
// };
// // { Driver Code Starts.
// int main()
//  {
//     int N;        
//     //taking N
//     cin>>N; 
//     Solution ob;
//     ob.exactly3Divisors(N);
//     //calling function exactly3Divisors()
//     //cout<<ob.exactly3Divisors(N)<<endl;
//     return 0;
//  }  // } Driver Code Ends
