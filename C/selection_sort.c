#include <stdio.h>
#include <conio.h>

void scan_array(int* array,int n){
    for (int i=0;i<n;i++){
        printf("\nEnter %d:- ",i);
        scanf("%d",&array[i]);
    }
}

void print_array(int* array,int start,int end){
    printf("[");
        for (int i=start;i<end;i++){
            printf("%d,",array[i]);
        }
    printf("\b]\n\n");
}

void swap(int* array,int i,int min_pos){
    int extra = array[i];
    array[i] = array[min_pos];
    array[min_pos] = extra;
}

int find_min(int* array, int start, int n){
    int min = array[start];
    for (int i=start;i<n;i++){
        if(array[i]<min){
            min = array[i];
        }
    }
    for (int i=start;i<n;i++){
        if(array[i]==min){
            return i;
        }
    }
}

void selection_sort(int* array,int n){
    for(int i=0;i<n-1;i++){
        int min_pos = find_min(array,i+1,n);
        if(array[min_pos]<array[i]){
            swap(array,i,min_pos);
        }
        printf("\nPass %d:- ",i);
        print_array(array,0,n);
    }
}

void main(){
    int n;
    printf("\nEnter n:- ");
    scanf("%d",&n);
    int array[n];
    scan_array(array,n);
    selection_sort(array,n);
    printf("\nSorted Array:- ");
    print_array(array,0,n);
}