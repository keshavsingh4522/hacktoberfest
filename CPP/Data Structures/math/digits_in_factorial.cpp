// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int digitsInFactorial(int num)
    {
           if (num < 0){
      return 0;
   }
   // base case
   if (num <= 1){
      return 1;
   }
   // else iterate through num and calculate the
   // value
   double d = 0;
   for (int i=2; i<=num; i++){
      d += log10(i);
   }
   return floor(d) + 1;
}
 
};
// { Driver Code Starts.

int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;
        
        //taking N
        cin>>N;
        Solution ob;
        //calling method digitsInFactorial()
        cout<<ob.digitsInFactorial(N)<<endl;
    }
    return 0;
}
  // } Driver Code Ends