// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverse(vector<long long> arr,int low,int high)
{
    while(low<high)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
    // for(long long i = 0; i<arr.size(); i++){
    //         cout << arr[i] << " "; 
    //     }
    cout<<"done";
    //     cout << endl;
    

}
    void reverseInGroups(vector<long long>& arr, int n, int k){
        for(int i=0;i<arr.size()/k;i+=3)
        reverse(arr,i,i+k-1);cout<<"fuck";
        cout<<"out of loop ";
        // code here
    }
};

// { Driver Code Starts.
int main() { 
        int n;
        cout<<"enter n";
        cin >> n; 
        vector<long long> arr; 
        cout<<"enter k";
        int k;
        cin >> k; 
        cout<<"enter arraY";

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }

  // } Driver Code Ends=3) 