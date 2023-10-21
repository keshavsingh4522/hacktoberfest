  //bubble sort algorithm
  #include<stdio.h>
 void display(int arr[],int n){
     printf("array elements are: ");
     for(int i=0;i<n;i++){
         printf("%d ",arr[i]);
     }
     printf("\n");
 }
 int bubblesort(int arr[],int n){
     int i,j,temp;
     for(i=0;i<n-1;i++){
         for(j=0;j<n-1-i;j++){
             if(arr[j]>arr[j+1]){
                 temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]=temp;
             }
         }
     }
 }
 int main(){
     int arr[10]={1,2,3,4,56,71};
     int size=sizeof(arr)/sizeof(int);
     display(arr,size);
     bubblesort(arr,size);
     display(arr,size);
 }
