#include<iostream>

using namespace std;
int main()
{
	int n,m,i,j;
	cout<<"enter length of matrix r x c=";
	cin>>n>>m;
	int arr[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		cin>>arr[i][j];
		}
	}
	
	cout<<"\nMatrix is:";
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		cout<<arr[i][j]<<" ";
	    }
	}
	cout<<endl;
	return 0;
}
