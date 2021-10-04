class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) 
    {
        int row=m.size();
        int col=m[0].size();

        vector<int> res(row*col);
        int resi=0;

        int j;
        for(int i=0; i<row; i++)
        {
            if(resi==row*col)
                break;

            j=i;
            for(; j<col-i && resi!=row*col; j++)
            {
                res[resi++]=m[i][j];
            }

            int k;
            for(k=i+1; k<row-i-1 && resi!=row*col; k++){
                res[resi++]=m[k][j-1];
            }

            int l;
            for(l=j-1; l>=i && resi!=row*col; l--)
            {
                res[resi++]=m[k][l];
            }

            int m1;
            for(int m1=k-1; m1>i && resi!=row*col; m1--)
            {
                res[resi++]=m[m1][i];
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
