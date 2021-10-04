class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int> res(m*n);
        int resi=0;

        int j;
        for(int i=0; i<m; i++)
        {
            if(resi==m*n)
                break;

            j=i;
            for(; j<n-i && resi!=m*n; j++)
            {
                res[resi++]=matrix[i][j];
            }

            int k;
            for(k=i+1; k<m-i-1 && resi!=m*n; k++){
                res[resi++]=matrix[k][j-1];
            }

            int l;
            for(l=j-1; l>=i && resi!=m*n; l--)
            {
                res[resi++]=matrix[k][l];
            }

            int m1;
            for(int m1=k-1; m1>i && resi!=m*n; m1--)
            {
                res[resi++]=matrix[m1][i];
            }
        }
        vector<int>::iterator it;
        for(it=res.begin(); it!=res.end(); it++)
        {
            cout<<*it;
        }
        return res;
    }
};
