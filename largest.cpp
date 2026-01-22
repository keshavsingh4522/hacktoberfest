def find_kth_largest(nums, k):
    # Sort the array in descending order
    nums.sort(reverse=True)
    # Return the kth largest number
    return nums[k - 1]

nums = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
k = 3
result = find_kth_largest(nums, k)
print(f"The {k}th largest number is: {result}")
