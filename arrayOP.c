#include<stdio.h>
#include<string.h>
#include<conio.h>

void display(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");    
}

int InsertByIndex(int arr[], int size, int index, int element){
    if(index < 0){
        return -1;
    }
    for(int j = size-1; j>=index; j--){
        arr[j+1] = arr[j];
    }
    arr[index] = element;
    return 1;
}

void deleteByIndex(int arr[],int index, int size){
    if(index < 0){
        printf("Enter correct position\n");
    }
    for (int j = index; j < size; j++)
    {
        arr[j] = arr[j+1];
    }    
}

int main(){
    int arr[100];
    int size = 0,ele,index;
    char choice;
    printf("Creating array \n");
    printf("Enter no element in array : ");
    scanf("%d",&size);

    for(int i = 0; i < size; i++){
        printf("Enter Element no %d : ",(i+1));
        scanf("%d",&arr[i]);
    }

    printf("Your array is : \n");
    display(arr,size);
    printf("Your array is Created\n");
    printf("Now You can perform Operations\n");
    printf("1.Insert\t");
    printf("2.Delete\t");
    printf("3.Update\n");

    printf("Enter Choice : ");
    choice = getch();

    switch (choice)
    {
    case '1':
        // printf("Inserted");
        printf("\nEnter Element which you want to insert : ");
        scanf("%d",&ele);
        printf("Enter Position where you want to insert : ");
        scanf("%d",&index);

        InsertByIndex(arr,size,index-1,ele);
        size++;

        break;
    
    case '2':
        printf("\nEnter Position where you want to delete : ");
        scanf("%d",&index);

        deleteByIndex(arr,index-1,size);
        size--;
        break;
    
    case '3':
        printf("\nEnter Position where you want to update : ");
        scanf("%d",&index);
        printf("\nEnter Element which you want to update : ");
        scanf("%d",&ele);

        arr[index-1] = ele;        
    
    default:
        // printf("Now Our Array is : ");
        // display(arr,size);
        break;
    }
    printf("Now Our Array is : ");
    display(arr,size);
    
    
    return 0;
}
