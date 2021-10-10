#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

int partition(int arr[],int left,int right)
{
	int pivot=arr[right];
	int i=left-1;

	for(int j=left;j<right;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,right);
	return i+1;
}

void quick(int arr[],int left,int right)
{
	if(left<right)
	{
		int pivot=partition(arr,left,right);
		quick(arr,left,pivot-1);
		quick(arr,pivot+1,right);
	}
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	quick(arr,left,right);
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	return 0;
}
