#include<iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];     
        }
    }

    cout<<endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<<arr[i][j]<<" ";     
    //     }
    //     cout<<endl;
    // }

    int rs=0;
    int re=n-1;
    int cs=0;
    int ce=m-1;

    cout<<endl;
    while (rs<=re && cs<=ce)
    {
        for (int c = cs; c <= ce; c++)
        {
            cout<<arr[rs][c]<<" ";
        }
        rs++;
        
        
        for (int r = rs; r <= re; r++)
        {
            cout<<arr[r][ce]<<" ";
        }
        ce--;
        
        
        for (int c =ce; c >= cs; c--)
        {
            cout<<arr[re][c]<<" ";
        }
        re--;
        

        for (int r = re; r >= rs; r--)
        {
            cout<<arr[r][cs]<<" ";
        }
        cs++;

    }
    return 0;
}
