#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key)
{
    int start = 0;
    int ending = n - 1;
    while (start <= ending)
    {
        int mid = (start + ending) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            ending = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    cout << BinarySearch(arr, n, key);
    return 0;
}