#include <stdio.h>
int main() {
   int arr[]={10,9,8,7,6,5,4,3,2,1};
   int n=10;
   int i, j, pos, temp;
   for (i = 0; i < (n - 1); i++) {
      pos = i;
      for (j = i + 1; j < n; j++) {
         if (arr[pos] > arr[j])
            pos = j;
      }
      if (pos != i) {
         temp = arr[i];
         arr[i] = arr[pos];
         arr[pos] = temp;
      }
   }
   for (i = 0; i < n; i++)
      printf("%d ", arr[i]);
   return 0;
}