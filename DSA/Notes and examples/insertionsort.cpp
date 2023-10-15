//insert element from unsorted array to its correct postion in sorted array
#include <iostream>
using namespace std;

void insertionSort()
{
  int i,j,current;
  int arr[]={10,2,3,4,5};
  
  for(i=1;i<5;i++)
  {
      current=arr[i];
      j=i-1;
      while(arr[j]>current && j>=0)
      {
          arr[j+1]=arr[j];
          j--;
      }
      arr[j+1]=current;
  }
  
  cout<<"sorted array:\n";
  for(i=0;i<5;i++)
  cout<<arr[i]<<" \n";
}


int main() {
    int arr[]={10,2,3,4,5};
    // int i,j,temp;
    cout<<"given array is:\n";
    for(int i=0;i<5;i++)
    cout<<arr[i]<<" \n";
    insertionSort();
    return 0;
}
