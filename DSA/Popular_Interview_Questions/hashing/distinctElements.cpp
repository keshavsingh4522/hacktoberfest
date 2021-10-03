// Find the total number of disctinct elements in an array
int findElement(int arr[], int n){
    unordered_set<int> d(arr,arr+n);
    return d.size();
}
