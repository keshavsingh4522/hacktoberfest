/* Maximum of Minima of all windows of size k 

    For a list of numbers,
    Find the maximum of minima of all windows of size k

    For example if array = [1,2,3,4,5,6]
    and window size, k = 3
    then 
    windows  | minimum
    [1,2,3]  |  1
    [2,3,4]  |  2
    [3,4,5]  |  3
    [4,5,6]  |  4

    Then maximum of minima = 4

    Approach:

    Hash the first window using ordered map,
    and store the first element of hash as answer

    then hash subsequent windows and for each window
    decrease one instance first element of previous window and 
    if that number is not present in new window remove it.

    Add the new element and again take the first element of map and maximise it.

*/

#include <bits/stdc++.h>

using namespace std;

int main() 
{  
    int n = 6;  // size of array
    int nums[n] = {1, 2, 3, 4, 5, 6};
    int k = 3;  // window size
    int maxx = INT_MIN;

    map<int,int>hash;
    for(int i=0;i<k;i++) 
        hash[nums[i]]++;    // hashing first k numbers

    auto it=hash.begin();        
    maxx = it->first;       // first element of map is smallest
    for(int i=k;i<n;i++)
    {   
        hash[nums[i-k]]--;  // excluding first value of last window

        // if the first value of last window is not in new / current window
        if(  hash[nums[i-k]] ==0)
            hash.erase(nums[i-k]);  // removing the value

        hash[nums[i]]++;    // adding current element to new window

        auto it = hash.begin(); // taking the first value
        maxx = max(maxx,it->first); // maximising the minima
    }
    cout<<maxx;     // answer
    return 0;
}
