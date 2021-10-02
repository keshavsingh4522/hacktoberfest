 int removeElement(vector<int>& arr, int val) {
        int res = 0;
       for(int i=0; i<arr.size(); i++){
           if(arr[i] != val){
               arr[res] = arr[i];
               res++;
           }
       }
        
        return res;
    }