#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> Set;
        long long sum = 0;
        int n = nums.size();
        vector<vector<int>> result;
        int left, right;
        
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                left = j + 1;
                right = n - 1;
                while (left < right) {
                    sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        Set.insert({nums[i], nums[j], nums[left], nums[right});
                        left++;
                        right--;
                    }
                }
            }
        }
        
        for (auto it : Set) {
            result.push_back(it);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int target;
    int num;
    
    cout << "Enter the target sum: ";
    cin >> target;
    
    cout << "Enter the elements of the array (type a non-integer to stop):\n";
    while (cin >> num) {
        nums.push_back(num);
    }

    vector<vector<int>> result = solution.fourSum(nums, target);

    for (const vector<int>& quad : result) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

