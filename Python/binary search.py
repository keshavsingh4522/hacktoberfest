# Binary Search in Python

def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid  # target found
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1  # target not found


# Get input from user
arr = list(map(int, input("Enter sorted numbers separated by space: ").split()))
target = int(input("Enter the number to search: "))

# Perform binary search
result = binary_search(arr, target)

if result != -1:
    print(f"Element found at index {result}")
else:
    print("Element not found in the list")
