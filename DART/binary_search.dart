void main() {
  List<int> arr = [0, 2, 3, 5, 7, 11, 13, 17];
  int userVal = 3;
  int min = 0;
  int max = arr.length - 1;
  bst(arr, userVal, min, max);
}

//binary search tree
bst(List<int> arr, int userVal, int min, int max) {
  if (max >= min) {
    print('min $min');
    print('max $max');
    int mid = ((max + min) / 2).floor();
    if (userVal == arr[mid]) {
      print('Your value is at index: ${mid}');
    } else if (userVal > arr[mid]) {
      bst(arr, userVal, mid + 1, max);
    } else {
      bst(arr, userVal, min, mid - 1);
    }
  }
  return null;
}
