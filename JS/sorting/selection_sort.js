/******************************* SELECTION SORT ******************************/
/* principle -> 
    first make the first element the smallest element and compare with all other elements, if smaller number is found then make it smallest number. continue this process and push smallest element of every iteration in new array.
*/
const selectionSort = (arr) => {
    let smallest = arr[0]
    let smallestIndex = 0;
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i]
            smallestIndex = i;
        }
    }
    return smallestIndex
}

const sorting = (arr) => {
    const newArr = []
    const length = arr.length
    for (let i = 0; i < length; i++) {
        let smallestIndex = selectionSort(arr)
        newArr.push(...arr.splice(smallestIndex, 1))
    }
    console.log(newArr)
}
sorting([5, 3, 6, 2, 10]) //BigO -> O(n*n) it actually is  O(n x n x 1/2) but we ignore the constants bestCase -> O(n*n)

/******************************* SELECTION SORT ******************************/