// Find the first non-repeating element in a given array arr of N integers.
// Note: Array consists of only positive and negative integers and not zero.
//
// Example 1:
//
// Input : arr[] = {-1, 2, -1, 3, 2}
// Output : 3
// Explanation:
// -1 and 2 are repeating whereas 3 is
// the only number occuring once.
// Hence, the output is 3.



class Solution{
    public:
    int firstNonRepeating(int arr[], int n)
    {
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp[arr[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mpp[arr[i]] == 1)
            {
                return arr[i];
            }
        }
        return 0;

    }

};
