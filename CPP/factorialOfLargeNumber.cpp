//  Problem Link: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
//  Problem : Given an integer N, find its factorial.
//  Input: N = 10
//  Output: 3628800
//  Explanation :
//  10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
//  Solution:

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
     vector<int> factorial(int N)
    {
        vector<int> v;
        v.push_back(1);
        for(int i=2; i<=N; i++)
        {
            int carry = 0;
            for(int j=0; j<v.size(); j++)
            {
                int mul = (v[j] * i) + carry;
                v[j] = mul % 10;
                carry = mul / 10;
            }
            while(carry)
            {
                v.push_back(carry % 10);
                carry = carry / 10;
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends


