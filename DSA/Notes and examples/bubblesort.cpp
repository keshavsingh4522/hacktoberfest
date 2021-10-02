//repeatedly swap adjacent elements if they are in wrong order
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void bubbleSort()
{
  int i;
  int arr[]={10,2,3,4,5};
  
  //for no.of iterations
  int counter=1;
  int temp;
  while(counter<5)
  {
      for(i=0;i<5-counter;i++)
      {
          if(arr[i]>arr[i+1])
          {
              //swapping
              temp=arr[i];
              arr[i]=arr[i+1];
              arr[i+1]=temp;
          }
      }
      //to jump to next iteration
      counter++;
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
    bubbleSort();
    return 0;
}
