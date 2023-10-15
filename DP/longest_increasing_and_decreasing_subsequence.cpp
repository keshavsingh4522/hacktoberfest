/*
Given an unsorted array on integers, find the length of its largest sub-sequence 
such that it is increasing at first and then decreasing and the number of elements 
in increasing and decreasing parts should be the same.

Example:
Input: 1 2 3 2 1 4 5 6 7 19 15 12 10 9
Output: 9
Explanation: Longest Increasing and Decreasing Sequence is:
				1 4 5 6 7 19 15 12 10 9 ==> 9 elements

*/


#include<iostream> 
#include <vector> 
#include <bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	int n,tmp,inc,dec;
	cin>>n;
	vector<int> ip;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		ip.push_back(tmp);
	}
	vector<int> lis(n,1);
	vector<int> lds(n,1);
	inc=0;
	dec=0;
	for(int i=1;i<n;i++)
	{
		if(ip[i]>ip[i-1])
		{
			lis[i]=lis[i]+(++inc);
		}
		else
		{
			inc=0;
		}
	}
//	cout<<ip[n-1]<<"\t"<<lis[n-1]<<"\t"<<lds[n-1]<<lis[n-1]+lds[n-1]-1<<endl;
	for(int i=n-2;i>=0;i--)
	{
		
		if(ip[i]>ip[i+1])
		{
			lds[i]=lds[i]+(++dec);
		}
		else
		{
			dec=0;
		}
//		cout<<ip[i]<<"\t"<<lis[i]<<"\t"<<lds[i]<<"\t"<<lis[i]+lds[i]-1<<endl;
	}
	int mx= INT_MIN;
	for(int i=0;i<n;i++)
	{
//		cout<<2*min(lis[i],lds[i])-1<<endl;
		mx=max(2*min(lis[i],lds[i])-1,mx);
	}
	cout<<mx;
}
