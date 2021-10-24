function swap(arr, idx1, idx2) {
    let temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
    return arr;
}

function bubbleSort(arr) {
    for(let i=arr.length-1; i>=0; i--) {
        for(let j=0; j<arr.length; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr, j, j+1);
            }
        }
    }
    return arr;
}

bubbleSort([3,4,1,2,5]);
