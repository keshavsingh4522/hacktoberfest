bool checkIfExists(vector<int> arr){
    int n = arr.size();
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        if(mp.find(arr[i]*2) != mp.end()){
            return true;
        }
        if(arr[i]%2==0 && mp.find(arr[i]/2) != mp.end()){
            return true;
        }
        mp[arr[i]]++;
    }

    return false;
}