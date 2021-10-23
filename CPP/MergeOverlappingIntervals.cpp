#include<bits/stdc++.h> 
using namespace std; 
struct Interval 
{ 
	int s, e; 
};  
bool mycomp(Interval a, Interval b) 
{ return a.s > b.s; } 

void mergeIntervals(Interval arr[], int n) 
{
    sort(arr, arr+n, mycomp); 
	int index = 0; 
	for (int i = 0; i < n; i++) 
	{ 
		if(index != 0 && arr[index-1].s <= arr[i].e)
        {
            while(index != 0 && arr[index-1].s <= arr[i].e)      
            {
                arr[index-1].e = max(arr[index-1].e, arr[i].e); 
			    arr[index-1].s = min(arr[index-1].s, arr[i].s);
                index--;
            }
        }
		else arr[index] = arr[i]; 
		index++; 
    }
    cout<<"The Merged Intervals are: "; 
	for(int i = 0; i < index; i++) 
		cout<<"["<<arr[i].s<<","<<arr[i].e<<"]"<<' '; 
} 

int main() 
{ 
    int n;
    cin>>n;
	Interval arr[n];
    for(int i = 0; i < n; ++i)
    {
        cin>>arr[i].s>>arr[i].e;
    } 
	mergeIntervals(arr, n); 
	return 0; 
} 
