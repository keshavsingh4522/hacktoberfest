#include <iostream>
using namespace std;

int divide = 0, conquer = 0, combine = 0, cnt = 0;
void Merge(int arr[], int left, int mid, int right)
{
    cnt++; // function call
    int temp[right + 1];
    int i = left;
    cnt++; // i = left

    int j = mid + 1;
    cnt++; // j = mid + 1

    int k = left;
    cnt++; // k=left

    while (i <= mid && j <= right)
    {
        cnt++; // while loop condition

        cnt++; // if condition
        if (arr[i] < arr[j])
        {
            cnt++; // temp[k] = arr[i]
            temp[k] = arr[i];
            i++;
            cnt++; // i++
            k++;
            cnt++; // k++
        }
        else
        {
            cnt++; // temp[k] = arr[j]
            temp[k] = arr[j];
            j++;
            cnt++; // j++
            k++;
            cnt++; // k++
        }
    }
    cnt++; // while false condition

    while (i <= mid)
    {
        cnt++; // while loop condition
        temp[k] = arr[i];
        cnt++; // temp[k] = arr[i]
        k++;
        cnt++; // k++
        i++;
        cnt++; // i++
    }
    cnt++; // while loop false condition

    while (j <= right)
    {
        cnt++; //temp[k] = arr[i]
        temp[k] = arr[j];
        k++;
        cnt++; // k++
        j++;
        cnt++; // j++
    }
    cnt++; // while loop false condition

    cnt++; // i = left
    for (int i = left; i < k; i++)
    {
        cnt++; // i < k
        arr[i] = temp[i];
        cnt++; // arr[i] = temp[k]
        cnt++; //i++
    }
    cnt++; // for loop false condition
}
void MergeSort(int arr[], int left, int right)
{
    cnt++; // function call
    conquer++;

    cnt++; // if condition
    if (left < right)
    {
        int mid = (left + right) / 2;
        cnt++; // mid

        divide++;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
        combine++;
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array:  ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MergeSort(arr, 0, n - 1);

    cout << "Sorted array is ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << "Total number of instruction are : " << cnt;
    cout << endl
         << "Total number of divide are : " << divide;
    cout << endl
         << "Total number of conquer are : " << conquer;
    cout << endl
         << "Total number of combine are : " << combine;
}
