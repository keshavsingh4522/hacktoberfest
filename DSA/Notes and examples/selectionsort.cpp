//find min value element of an unsorted array and swap it with first element
#include <iostream>
using namespace std;

void selectionSort()
{
  int i,j,temp;
  int arr[]={10,2,3,4,5};
  for(i=0;i<4;i++)
  {
      for(j=i+1;j<5;j++)
      {
          if(arr[j]<arr[i])
          {
              //swapping	
              temp=arr[j];
              arr[j]=arr[i];
              arr[i]=temp;
          }
      }
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
    selectionSort();
    return 0;
}
