#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
int big=i; // Initialize big as root
int l=2*i+1; // left = 2*i + 1
int r=2*i+2; // right = 2*i + 2
if (l<n && arr[l]>arr[big])
big= l;
if (r<n&&arr[r]>arr[big])
big=r;
if (big!= i) {
swap(arr[i], arr[big]);
heapify(arr, n, big);
}
}
//Sorting the heap
void Sort(int arr[], int n)
{
for (int i = n / 2 - 1; i >= 0; i--)
heapify(arr, n, i);
for (int i=n-1; i>0; i--)
{
swap(arr[0], arr[i]);
heapify(arr, i, 0);
}
}
//printing the heap
void printH(int arr[], int n)
{
for (int i=0; i<n; ++i)
cout << arr[i] << " ";
cout << "\n";
}
// Driver program
int main()
{
int n, i;
cout<<"ENTER THE HEAP SIZE\n";
cin>>n;
int arr[50];
for (i = 0; i < n; i++) {
cout<<"Enter heap elements"<<" "<<(i+1)<<endl;
cin>>arr[i];
}
Sort(arr, n);
cout << "Sorted heap array is \n";
printH(arr, n);
}
