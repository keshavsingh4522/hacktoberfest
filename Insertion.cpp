#include <stdio.h>

void printarr(int *a,int n){
    for (int m=0;m<n;m++){
        printf("%d\n",a[m]);
    }
}

void insertion(int *a,int n){
    int key,j;
    for (int i=1;i<=n-1;i++){
        key=a[i];
        j=i-1;
        
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int k=0;k<n;k++){
        scanf("%d",&arr[k]);
    }
    
    insertion(arr,n);
    printarr(arr,n);
    
    return 0;
}	 	  	 	 		   	    	  	    	     	 	
