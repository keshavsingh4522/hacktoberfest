#include<bits/stdc++.h>
using namespace std;
 
//Efficient implementation with time complexity - O(N).
int maxWater(int arr[], int n)
{
    int left = 0; 
    int right = n-1;
    int res = 0;
    int maxleft = 0, maxright = 0;
    while(left <= right)
    {
        if(arr[left] <= arr[right])
        {
            if(arr[left] >= maxleft) 
                maxleft = arr[left];
            else 
                res += maxleft-arr[left];
            
            left++;
        }
        else
        {
            if(arr[right] >= maxright) 
                maxright = arr[right];
            else
                res += maxright-arr[right];
            
            right--;
        }
    }
    return res;
}
 
int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
     
    cout << maxWater(arr, n);
     
    return 0;
}
