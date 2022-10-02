#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*start = NULL;

void display(){

    struct node *ptr;

    if(start==NULL){
        printf("\nList is empty!\n");
        return;
    }
    else{

        ptr=start;
        printf("\nThe List elements are:");
    
        while(ptr!=NULL){
            printf("%d ",ptr->data );
            ptr=ptr->next;
        }
        printf("\n");
    }
}

void insert_begin(){

    struct node *temp;

    temp=(struct node *)malloc(sizeof(struct node));
    
    if(temp==NULL){
        printf("\nOut of Memory Space\n");
        return;
    }

    printf("\nEnter the data value for the node:" );
    scanf("%d",&temp->data);

    temp->next =NULL;
    
    if(start==NULL)
        start = temp;
    
    else{
        temp->next=start;
        start=temp;
    }
}
    
void insert_end(){

    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    
    if(temp==NULL){
        printf("\nOut of Memory Space\n");
        return;
    }

    printf("\nEnter the data value for the node:" );
    scanf("%d",&temp->data );
    temp->next =NULL;

    if(start==NULL)
        start = temp;
    else{
        ptr=start;
        while(ptr->next !=NULL)
            ptr = ptr -> next ;
        ptr -> next = temp;
    }

}

void insert_pos(){

    struct node *ptr,*temp;
    int i,pos;
    temp=(struct node *)malloc(sizeof(struct node));

    if(temp==NULL){
    printf("\nOut of Memory Space!\n");
    return;
    }

    printf("\nEnter the position for the new node to be inserted:");
    scanf("%d",&pos);
    printf("\nEnter the data value of the node:");
    scanf("%d",&temp->data) ;
    temp->next=NULL;

    if(pos==0){
        temp -> next = start;
        start = temp;
    }
    
    else{
    
        for(i=0,ptr=start;i<pos-1;i++){ 
            ptr=ptr->next;
    
        if(ptr==NULL){
            printf("\nPosition not found:[Handle with care]");
            return;
        }
    }

        temp -> next = ptr -> next ;
        ptr -> next = temp;
    }
}

void delete_begin(){
    
    struct node *ptr;
    
    if(ptr == NULL){
        printf("\nList is Empty!\n");
        return;
    }
    else{
        ptr=start;
        start = start->next ;
        printf("\nThe deleted element is :%d \n",ptr->data);
        free(ptr);
    }

}

void delete_end(){

    struct node *temp,*ptr;

    if(start==NULL){
        printf("\nList is Empty!\n");
        exit(0);
    }

    else if(start->next ==NULL){
        ptr=start;
        start=NULL;
        printf("\nThe deleted element is:%d \n",ptr->data);
        free(ptr);
    }

    else{
        ptr=start;

        while(ptr->next!=NULL){
            temp=ptr;
            ptr=ptr->next;
        }

        temp->next=NULL;
        printf("\nThe deleted element is:%d \n",ptr->data);
        free(ptr);
    }
}

void delete_pos(int pos){

    int i;
    struct node *temp,*ptr;
    
    if(start==NULL){
        printf("\nThe List is Empty!\n");
        exit(0);
    }

    else{
        
        if(pos==0){
            ptr=start;
            start=start->next;
            printf("\nThe deleted element is:%d \n",ptr->data );
            free(ptr);
        }
        
        else{
            ptr=start;
            for(i=0;i<pos;i++){
                temp=ptr; 
                ptr=ptr->next;
                
                if(ptr==NULL){
                    printf("\nPosition not Found\n");
                    return;
                }
            }

            temp->next = ptr->next ;
            printf("\nThe deleted element is:%d ",ptr->data );
            printf("\n");
            free(ptr);
        }
    }
}

void Search(){

    struct node* temp;
    temp = start;

    int item;
    printf("\nEnter the number to be searched: ");
    scanf("%d",&item);

    int pointer = 0;
    while(temp != NULL){
        if(temp->data == item){
            printf("Item found at Index: %d",pointer);
            break;
        }
        else{
            temp = temp->next;
            pointer++;
        }
    }

}

void deletebyvalue(){

    int num;
    struct node* temp;
    temp = start;

    if (start == NULL)
        printf("\nList is empty\n");
    
    else {
        printf("\nEnter Value to be deleted : ");
        scanf("%d", &num);
    }

    int count = 1;

    while(temp->data != num){
        temp = temp->next;
        count++;
    }

    if(count > 0){
        delete_pos(count-1);
    }

}

void Reverse(){

    struct node* temp = start;
    struct node *prev = NULL, *next = NULL;
 
    while (temp != NULL) {
            
        next = temp->next;
            
        temp->next = prev;
            
        prev = temp;
        temp = next;

    }
    start = prev;

    printf("After Reversing the List");
    display();

}

void EvenOddCount(){

    struct node* temp;
    temp = start;

    if(start == NULL){
        printf("The List is Empty!!");
        exit(0);
    }

    int ocount = 0;
    int ecount = 0;

    while(temp != NULL){

        int num = temp->data;

        if(num%2==0)
            ecount++;
        else
            ocount++;
        
        temp = temp->next;

    }

    printf("\nThe count of Odd number is - %d",ocount);
    printf("\nThe count of Even number is - %d",ecount);

}

int main() {
    
    int choice,pos;

    while(choice != 12){
        
        printf("\n");
        printf("1.Insertion at beginning \n");
        printf("2.Insertion at end\n");
        printf("3.Insert at specified position\n");
        printf("4.Delete based on value\n");
        printf("5.Delete based on specified position\n");
        printf("6.Delete from beginning\n");
        printf("7.Delete from the end\n");
        printf("8.Search an element\n");
        printf("9.Reverse the List\n");
        printf("10.Even Odd Count\n");
        printf("11.Display the List\n");
        printf("12.Exit\n");
        printf("Enter your choice:\n");

        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert_begin();
                break;
            case 2:
                insert_end();
                break;
            case 3: 
                insert_pos();
                break;
            case 4:
                deletebyvalue();
                break;
            case 5:
                printf("Enter the position of the node to be deleted:");
                scanf("%d ",&pos);
                delete_pos(pos-1);
                break;
            case 6:
                delete_begin();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                Search();
                break;
            case 9:
                Reverse();
                break;
            case 10:
                EvenOddCount();
                break;
            case 11:
                display();
                break;
            case 12:
                exit(0);
                break;
            default:
                printf("\n Wrong Choice:\n");
                break;
        }
    }
    return 0;
}   
