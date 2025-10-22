//Submission for Hacktober Fest 2021

/*
Question: Selection Sort
Submitted by:- nehamotwani80
Language Used:- C++
*/

#include<bits/stdc++.h>
using namespace std;
void swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
int main()
{
	int n,i,j,min_index;
	cin>>n;
	int arr[n];
	cout<<"enter the array:-"<<endl;
	for(i=0;i<n;i++)
	cin>>arr[i];
	
	min_index=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min_index])
			{
				min_index=j;
			}
		}
		swap(&arr[i],&arr[min_index]);
	}
	cout<<"sorted array is:-"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}
