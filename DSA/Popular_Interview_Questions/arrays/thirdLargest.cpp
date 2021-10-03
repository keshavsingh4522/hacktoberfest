int thirdMax(int arr[], int n){
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    int curr = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == max1 || arr[i]==max2 ||arr[i]==max3){
            continue;
        }
        curr++;
        if(arr[i]>max1){
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        if(arr[i]>max2){
            max3 = max2;
            max2 = arr[i];
        }
        if(arr[i]>max3){
            max3 = arr[i];
        }
    }

    if(curr>2){
        return max3;
    }

    return max1;

}