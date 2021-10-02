#include <iostream>

using namespace std;


void insertionsort( int arr[], int n)
{
    int key , j;
   for(int i=1; i<n; i++)
   {
       key = arr[i];
       j = i-1;

       while( j>=0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
       }


}
void printarr(int arr[] , int n)
{
    for(int i=0; i<n; i++)
       {
           cout <<arr[i]<<endl;

       }
}


int main()
{
    int arr[10];
    int n;
    cout <<"Enter value of n" <<endl;
    cin >> n;

    cout << "Enter array value" << endl;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    insertionsort(arr , n);
    printarr(arr , n);
    return 0;
}
