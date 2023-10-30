using System;

class Program {

  static void Main(string[] args) {

    int[] arr = {64, 34, 25, 12, 22, 11, 90};

    Console.WriteLine("Unsorted array:");
    PrintArray(arr);

    BubbleSort(arr);

    Console.WriteLine("\nSorted array:");
    PrintArray(arr);
  }

  static void BubbleSort(int[] arr) {

    for (int i = 0; i < arr.Length - 1; i++) {
      for (int j = 0; j < arr.Length - i - 1; j++) {
        if (arr[j] > arr[j+1]) {
          int temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
        }
      }
    }
  }

  static void PrintArray(int[] arr) {
    foreach (int element in arr) {
      Console.Write(element + " ");
    }
  }
}

//Unsorted array: 
//64 34 25 12 22 11 90 

//Sorted array:
//11 12 22 25 34 64 90
