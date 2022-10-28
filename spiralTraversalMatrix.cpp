
//Q1- Spiral traversal of Matrix 

// { Driver Code Starts
#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > m, int r, int c) 
    {
        // code here
        vector<int> a;
        int top=0,left=0,right =c-1,bottom=r-1;
        
        while(top<=bottom && left<=right){
            
            // traverse top row (left to right)
            
            for(int i=left;i<=right;i++)
             a.push_back(m[top][i]);
            top++;
            
            //traverse right column (top to down)
            for(int i=top;i<=bottom;i++)
            a.push_back(m[i][right]);
            right--;
            
            //traverse right bottom to left column
            if(top<=bottom){
                 for(int i=right;i>=left;i--)
                a.push_back(m[bottom][i]);
                bottom--;
            }
            
            //traverse left bottom to top(left column)
            
            if(left<=right){
                 for(int i=bottom;i>=top;i--)
                a.push_back(m[i][left]);
                left++;
            }
            
            
        }
        return a;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
