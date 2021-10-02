#include <iostream>
using namespace std;

void shiftall(int arr[], int left, int right){
    while (left<=right)
  {
    if (arr[left] < 0 && arr[right] < 0)
      left+=1;
     
    else if (arr[left]>0 && arr[right]<0)
    {
      int temp=arr[left];
      arr[left]=arr[right];
      arr[right]=temp;
      left+=1;
      right-=1;
    }
     
    else if (arr[left]>0 && arr[right] >0)
      right-=1;
    else{
      left += 1;
      right -= 1;
    }
  }
}

void display(int arr[], int right){
   
  for (int i=0;i<=right;++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{
    int arr[] = {-12, 11, -13, -5,
               6, -7, 5, -3, 11};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
   
  shiftall(arr,0,arr_size-1);
  display(arr,arr_size-1);

    return 0;
}
