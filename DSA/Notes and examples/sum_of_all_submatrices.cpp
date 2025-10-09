#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[100][100];
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cin>>arr[i][j];
    }

    int top_left,bottom_right;
    int sum=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            top_left=(i+1)*(j+1);
            bottom_right=(n-i)*(n-j);

            sum+=(top_left*bottom_right*arr[i][j]);
        }
    }
    cout<<sum<<endl;
}

