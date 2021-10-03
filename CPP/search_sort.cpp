#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int k){
    //n->size     k->element need to be searched
    for(int i = 0; i<n; i++){
        if(arr[i] == k){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int k){
    //when array is sorted
    //n->size     k->element need to be searched
    int left = 0, right = n-1;
    int mid;
    while(left <= right){
        mid = (left+right)/2;
        if(arr[mid] == k){
            return mid;
        }
        else if(arr[mid] > k){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return -1;
}
void selectionSort(int arr[], int n){
    int temp, ind;
    for(int i=0; i<n; i++){
        ind = i;
        for(int j = i; j<n; j++){
            if(arr[j] < arr[ind]){
                ind = j;
            }
        }
        if(ind != i){
            temp = arr[i];
            arr[i] = arr[ind];
            arr[ind] = temp;
        }
    }
    return;
}

void bubbleSort(int arr[], int n){
    int n_swap, temp;
    for(int i = 0; i<n; i++){
        n_swap = 0;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                n_swap++;
            }
        }
        if(n_swap == 0){
            return;
        }
    }
}

void insertionSort(int arr[], int n){
    int temp;
    for(int i = 1; i<n; i++){
        int j = i;
        while(arr[j] < arr[j-1] && j>0){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
    return;
}

void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(int i = 0; i<n1; i++){
        L[i] = arr[l + i];
    }
    for(int i = 0; i<n2; i++){
        R[i] = arr[i+m+1];
    }
    int p = 0, q = 0;
    int k = l;
    while(p<n1 && q<n2){
        if(L[p] < R[q]){
            arr[k] = L[p];
            p++;
        }
        else{
            arr[k] = R[q];
            q++;
        }
        k++;
    }
    while(p<n1){
        arr[k] = L[p];
        p++;
        k++;
    }
    while(q<n2){
        arr[k] = R[q];
        q++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l>=r){
        return;
    }
    int m = (l + r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int pIndex = start;
    int temp;
    for(int i = start; i<=end-1; i++){
        if(pivot >= arr[i]){
            temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }
    temp = arr[pIndex];
    arr[pIndex] = arr[end];
    arr[end] = temp;
    return pIndex;
}

void quickSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int pInd = partition(arr, start, end);
    quickSort(arr, start, pInd-1);
    quickSort(arr, pInd+1, end);
}

int main(){
    int n = 5;
    int arr[n] = {4, 1, 3, 9, 7};
    quickSort(arr, 0, n-1);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int r = binarySearch(arr, n, 3);
    cout<<r<<endl;
}
