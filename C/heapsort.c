#include<stdlib.h>
#include<stdio.h>
void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}
void min_heapify(int heap[], int sub_root, int length){
    int max = sub_root;
    while(max <= length){
        int here = max;
        int left = here * 2;
        int right = here * 2 + 1;
        if(left <= length && heap[left] > heap[max]) max = left;
        if(right <= length && heap[right] > heap[max]) max = right;
        if (max != here) swap(&heap[max],&heap[here]);
        else break;
    }
}
void build_heap(int heap[], int length){
    for(int i = length / 2; i >= 1; i--){
        min_heapify(heap, i, length);
    }
}
void heap_sort(int heap[], int heap_size){
    for (int i = heap_size; i >= 1; i--){
        swap(&heap[1],&heap[i]);
        min_heapify(heap,1,i-1);
    }
}

int main(){
    int heap[9] = {-1,12, 30, 21, 55, 25, 72, 45, 50};
    int length = sizeof(heap) / sizeof(int) - 1;
    build_heap(heap,length);
    heap_sort(heap,length);
    for (int i = 0; i < 9; i++){
        printf("%d\t",heap[i]);
    }
}