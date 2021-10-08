// one of many sorting algorithm, bubble sort.
const bubbleSort = (arr) => {
  for (var i = 0; i < arr.length; i++) {
    for (var j = 0; j < arr.length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        var temporary = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temporary;
      }
    }
  }

  console.log(arr);
};

// our unsorted array
var exampleArr = [123, 753, 236, 25, 7, 80, 75, 32, 19];

// try our bubbleSort() function
bubbleSort(exampleArr);
