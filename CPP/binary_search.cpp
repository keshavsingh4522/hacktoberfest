
int binsearch(int A[], int low, int high, int key){
    
    if (low<=high){
        int mid = low + (high-low)/2;

        if(key== A[mid]){
            return mid;
        }
        
        else if (key<A[mid]){
            return binsearch(A, low, mid-1, key);
        }
        
        else
        {
            return binsearch(A, low, mid+1, key);
        }
    }
    return -1;
}


//Iterative Method:

int binsearch(int A[], int low, int high, int key){

    while(low<=high){

        int mid = (low + high)/2;

        if (A[mid]==key){
            return mid;
        }

        else if(key<A[mid]){
            high = mid-1;
        }

        else
        {
            low = mid+1;
        }
        
    }
    return -1;
}
