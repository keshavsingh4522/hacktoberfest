/******************************* BUBBLE SORT ******************************/
/*
    principle: -> 
    in each iteration, compare the adjacent element and swap them if the order is not correct
*/
const bubbleSort = (array,n) => {
    for(let i = 0;i < n-1; i++ ){
        for(let j = 0; j < n-i-1; j++ ){
            if(array[j] > array[j+1]){
              [array[j],array[j+1]] = [array[j+1],array[j]] //swapping elements
            }
        }
    }
    return array
}
console.log(bubbleSort([3,5,1,6],4)) //BigO -> O(n*n) bestCase -> O(n) spaceComplexity -> O(n)

/******************************* BUBBLE SORT ******************************/