#include <bits/stdc++.h>
using namespace std;

int n, flag = -1, cnt = 0, comparison = 0, divide = 0, conquer = 0;
int binarySearch(string arr[], int left, int right, string key)
{
    int mid;
    cnt++; // function call
    if (left <= right)
    {
        mid = ((left + right) / 2);
        cnt++; // mid

        comparison++;
        if (key.compare(arr[mid]) == 0)
        {
            flag = mid;
            cnt++; // flag
            cnt++; // return
            return flag;
        }
        comparison++;
        if (arr[mid] < key)
        {
            divide++;
            binarySearch(arr, mid + 1, right, key);
        }
        else if (arr[mid] > key)
        {
            divide++;
            binarySearch(arr, left, mid - 1, key);
        }
    }
    conquer++;

    cnt++; // return
    return flag;
}

int main()
{
    cnt++; // flag = -1
    cout<<"Enter the size of array : ";
    cin >> n;
    int left = 0, right = (n - 1);
    int mid = 0;
    string arr[n], key;
    cout<<"Enter your sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter value to search: ";
    cin >> key;

    cnt++; // left = 0
    cnt++; // right = n-1

    int result = binarySearch(arr, left, right, key);
    if (result != -1)
    {
        cout << "Value found at index : " << result << endl;
    }
    else
    {
        cout << "No element found." << endl;
    }

    cout << "Total number of instruction are : " << cnt << endl;
    cout << "Total number of comparison are : " << comparison << endl;
    cout << "Total number of division occur : " << divide << endl;
    cout << "Total number of conquer are : " << conquer << endl;
}
