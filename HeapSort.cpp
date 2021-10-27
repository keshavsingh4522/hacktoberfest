#include <iostream> 
using namespace std; 

void heapify(int arr[], int n, int i) 
{ 
	int largest = i; 
	int l = 2*i + 1; 
	int r = 2*i + 2;
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 
		heapify(arr, n, largest); 
	} 
} 

void buildheap(int arr[],int n){
    for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i);
}

void heapSort(int arr[], int n)  
{  
	buildheap(arr,n); 

	for (int i=n-1; i>0; i--) 
	{ 
		swap(arr[0], arr[i]);
		heapify(arr, i, 0); 
	} 
} 

int main(void) 
{
	int a[10];
    cout << "Enter 10 elements of array: " << endl;
    for (int i=0; i<10; i++)
        cin >> a[i];
    cout << "Original Array is: ";
    for (int i=0; i<10; i++)
        cout << a[i] << " ";
	int n=sizeof(a)/sizeof(a[0]);
	cout <<"\nArray after sorting is: ";
	heapSort(a,n);
	for(int x: a)
	    cout<<x<<" ";
}