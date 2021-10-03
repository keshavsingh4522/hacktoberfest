void mergeSorted(vector<int> arr1, vector<int> arr2, int n, int m){
    int i=m-1; int j=n-1;
    for(int i= m+n-1; k>=0; k++){
        if(i>=0 && j>=0){
            if(arr1[i]>arr2[j]){
                arr1[k] = arr1[i--];
            }
            else{
                arr1[k] = arr2[j--];
            }
        }
        else if(j>=0){
            arr1[k] = arr2[j--];
        }
        else{
            break;
        }
    }
}