#include<stdio.h>
int main(){
    int j=4,a[5],temp=0;
    /*
    get arr
    swap first to last
    dec i and inc i upto it is equal or i<j
    */
    for(int increment=0;increment<5;increment++){
        scanf("%d",&a[increment]);
    }
    for(int i=0;i<5;i++){
        if(i<=j&&j>=0){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            j--;
        }
    }
    for(int i=0;i<5;i++){
        printf("%d",a[i]);
    }

    return 0;
}