/*Print HELLO using arrow operator->it uses to access character using
 pointer and link every node 
And,it is a perfect example of linked list
*/
#include<stdio.h>

struct node{
    char info;
    struct node *next;
};
struct node *head,*ptr;
int main()
{
    struct node temp1,temp2,temp3,temp4,temp5;
    struct node *ptr1,*ptr2,*ptr3,*ptr4,*ptr5;
    ptr1=&temp1;
    temp1.info='H';
    temp1.next=&temp2;
    

    ptr2=&temp2;
    temp2.info='E';
    temp2.next=&temp3;
    

    ptr3=&temp3;
    temp3.info='L';
    temp3.next=&temp4;
    

    ptr4=&temp4;
    temp4.info='L';
    temp4.next=&temp5;
    

    ptr5=&temp5;
    temp5.info='O';
    temp5.next=NULL;
    
     head=ptr1;
     ptr=head;

     while(ptr!=NULL){
         printf("%c",ptr->info);
         ptr=ptr->next;
     }
     return 0;
}
