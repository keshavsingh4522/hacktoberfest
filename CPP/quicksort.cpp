#include<iostream>
#include<cstdlib>
 
using namespace std;
 
// Swapping two values.
void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
 

int Partition(int a[], int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;
 

	for(i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}

	swap(&a[pivot], &a[index]);
 
	return index;
}
 

int RandomPivotPartition(int a[], int low, int high)
{
	int pvt, temp;
	 int n = rand();

	pvt = low + n%(high-low+1);
 

	swap(&a[high], &a[pvt]);
 
	return Partition(a, low, high);
}
 
int QuickSort(int a[], int low, int high)
{
	int pindex;
	if(low < high)
	{       pindex = RandomPivotPartition(a, low, high);
	 	QuickSort(a, low, pindex-1);
		QuickSort(a, pindex+1, high);
	}
	return 0;
}
 
int main()
{
	int n, i;
	cout<<"\nEnter the number of elements to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	QuickSort(arr, 0, n-1);
 
	// Printing the sorted data.
	cout<<"\nSorted Array ";
	for (i = 0; i < n; i++)
        	cout<<"  "<<arr[i];
 
	return 0;
}
	
