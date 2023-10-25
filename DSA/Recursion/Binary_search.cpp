// import all the necessary libraries
#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // If the target is found at the middle of the array, return its index
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is less than the middle element, search in the left half
        if (arr[mid] > target) {
            return binarySearchRecursive(arr, target, left, mid - 1);
        }

        // If the target is greater than the middle element, search in the right half
        return binarySearchRecursive(arr, target, mid + 1, right);
    }

    // If the target is not found in the array, return -1
    return -1;
}

int binarySearch(int arr[], int size, int target) {
    return binarySearchRecursive(arr, target, 0, size - 1);
}

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    
    int arr[100];
    cout << "Enter " << n << " array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target element you want to search: ";
    int target;
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
