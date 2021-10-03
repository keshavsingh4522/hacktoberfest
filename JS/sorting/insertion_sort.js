/******************************* INSERTION SORT ******************************/
/*
    principle: -> 
    in each iteration, compare the key element with all elements in it's left and keep changing the position until the key element is sorted
*/
const insertionSort = (array,n) => {
    for(let i = 0;i < n; i++ ){
        let key = array[i]  
        let j = i-1
        while( j >= 0 && key < array[j] ){
            array[j+1] = array[j]
            j = j-1;  //keep on looking to the left until the first element
        }
        array[j + 1] = key //place at the place where the key element fits
    }
    return array
}
console.log(insertionSort([3,5,1,6],4)) //BigO -> O(n*n) bestCase -> O(n) spaceComplexity -> O(n)

/******************************* INSERTION SORT ******************************/
