bool isMountain(vector<int> arr){
    int n = arr.size();
    if(n<3){
        return false;
    }
    int i=0; 
    while(arr[i]<arr[i+1] && i<n-1]){
        i++;
    }

    if(i==0 || i==n-1){
        return false;
    }

    while(i<n-1 && arr[i]>arr[i+1]){
        i++;
    }

    if(i==n-1){
        return true;
    }

    return false;
}