/*
Max Sum Subarray of size K (GFG - Easy)
https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/

Example 1:
Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.
----------------------------

Example 2:
Input:
N = 4, K = 4
Arr = [100, 200, 300, 400]
Output:
1000
Explanation:
Arr1 + Arr2 + Arr3  
+ Arr4 =1000,
which is maximum.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/
class Solution{
    static int maximumSumSubarray(int K, ArrayList<Integer> Arr,int N){
        
        int i = 0, j = 0;
        int sum = 0, max_sum = Integer.MIN_VALUE;
        
		//run a loop checking the end index of our window with size of array
        while(j < N){
            sum = sum + Arr.get(j);
            
            if(j-i+1 < K){	//if our window is less than given window size simply increase end index of our window
                j++;
            }
            else if(j-i+1 == K){	//only calculate sum if our window size is equal to given window size
                max_sum = Math.max(max_sum, sum);
                sum = sum - Arr.get(i);		//remove the element which is at start index to not consider in next window
                i++;
                j++;
            }
        }
        return max_sum;
    }
}