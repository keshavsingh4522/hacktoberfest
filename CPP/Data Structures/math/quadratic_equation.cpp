// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
 
class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
    float d=(b*b)-(4*a*c);
    vector<int>roots;
    if(d<0)
    {
    roots.push_back(-1);}
    else
    {
        float r1=floor(((-b)-sqrt(d))/(2*a));
        float r2=floor(((-b)+sqrt(d))/(2*a));
        roots.push_back(r1);
        roots.push_back(r2);
        sort(roots.begin(),roots.end(),greater<int>());//greater is passed to sort in descending order
               // code here
    }
     return roots; 
    }
};


// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code 