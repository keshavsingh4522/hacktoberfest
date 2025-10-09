/***** Median of 2 sorted arrays ******/
/***** Contributed by Raunak Gayen ******/
/***** Time Complexity - O(min(logn1,logn2)) ******/
/***** Space Complexity - O(1) ******/


#include<bits/stdc++.h>
using namespace std;

//function for median calculation
double findMedianSortedArrays(vector<int> arr1,vector<int> arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    if(n1 > n2)
        return findMedianSortedArrays(arr2,arr1);

    int left = 0;
    int right = n1;

    while(left <= right)
    {
        int cut1 = (left + right)/2;
        int cut2 = (n1 + n2 + 1)/2 - cut1;

        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

        int r1 = cut1 == n1 ? INT_MAX : arr1[cut1];
        int r2 = cut2 == n2 ? INT_MAX : arr2[cut2];

        if(l1 <= r2 && l2 <= r1)
        {
            if((n1 + n2) % 2 == 0)
                return (double)(max(l1,l2) + min(r1,r2))/2.0;
            else
                return (double)max(l1,l2); 
        }
        else if(l1 > r2)
        {
            right = cut1 - 1;
        }
        else
        {
            left = cut1 + 1;
        }
    }

    return 0.0;
    
}


int main()
{
    int n1,n2;
    cin>>n1>>n2; // n1 -> size of 1st array and n2 -> size of 2nd array
    vector<int> arr1(n1);
    vector<int> arr2(n2);

    for(int i = 0; i < n1; i++) cin>>arr1[i]; // taking inputs for 1st array

    for(int i = 0; i < n2; i++) cin>>arr2[i]; // taking inputs for 2nd array

    //lets deal with the smaller array first

    double median = findMedianSortedArrays(arr1,arr2);

    cout<<"The median of the 2 sorted arrays is: "<<median;

}