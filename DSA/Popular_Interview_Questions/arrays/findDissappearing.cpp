vector<int> findDissapeared(vector<int> arr){
    vector<int> res;
    int n = arr.size(n);
    for(int i=0; i<n; i++){
        int temp = abs(arr[i]) -1;
        arr[temp] = arr[temp]>0 ? -arr[temp]:arr[temp];
    }

    for(int i=0; i<n; i++){
        if(arr[i]>0){
            res.push_back(i+1);
        }
    }

    return res;
}