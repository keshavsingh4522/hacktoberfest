//The question is to find the number of rectangles that can be formed parallel to x axis and y axis when coordinates are enteres by user.
// I have solved this question with O(n4) complexity. You can think of a better solution and commit the changes.


#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, count =0;

    printf("Enter nummber of co-ordinates you want to enter: ");
    scanf("%d",&n);
    int arr[n][2];
    
    for(int i=0; i<n; i++){
        printf("Enter co-ordinates %d: ", i+1);
        for(int j =0; j<2; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j==i){}
            else{
                if(arr[j][0]==arr[i][0]){
                    for(int k=0; k<n; k++){
                        if(k==i){}
                        else{
                            if(arr[k][1]==arr[i][1]){
                                for(int l=0; l<n; l++){
                                    if(l==k){}
                                    else{
                                        if(arr[l][0]==arr[k][0]){
                                            if(arr[l][1]==arr[j][1]){
                                                count++;
                                            }    
                                        }                                    
                                    } 
                                }
                            }                        
                        }
                    }
                }            
            }
        }
    }
    printf("\nNumber of rectangles: %d", count/4);

    return 0;
}
