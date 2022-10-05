#include <stdio.h>
#include <stdlib.h>

void LinearSearch (int x[], int size, int val);
int main (void) {
  int number[8] = {5,7,8,10,11,32,40,81};
  LinearSearch (number, 8, 8);
  return 0;
}

void LinearSearch (int x[], int size, int val) {
  int a,b;
  for (a =0; a<size; a++) {
    b = 0;
    if (x[a] == val) {
      printf ("The Index is:- %d\n",a);
      break;
    } else
      b = 1;
  } if (b == 1)
    printf("Element Not Found\n");
}
