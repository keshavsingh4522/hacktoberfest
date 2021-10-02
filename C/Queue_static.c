#include<stdio.h>
int x[5] , rear  , front;
void insert();
void delete1();
void display();
int main(){
int op;
do{
        printf("\n------MENU------");
        printf("\n 1)Insert \n 2) Delete \n 3) Display\n 0)Exit");
        printf("\n Enter your option::");
        scanf("%d" , &op);
        switch (op){
    case 1:
        insert();
        break;
    case 2:
        delete1();
        break;
    case 3:
        display();
        break;
    case 0:
        printf("\n Good Bye!");
        return 1;
    default:
        printf("\n Invalid Option");
        }
    }while(1);
}
void insert(){
if(rear == 5){
    printf("\n Queue is full!");
    return;
    }
    printf("\n Enter element in Queue::");
    scanf("%d", &x[rear]);
    rear++;
}
void delete1(){
if(rear == front){
   printf("\n Queue is Empty!");
   return;
}
printf("%d is deleted." , x[front]);
front++;
}
void display(){
int i;
if(rear == front){
   printf("\n Queue is Empty!");
   return;
}
printf("\n");
for(i=front ; i<=rear-1; i++){
    printf("%d " , x[i]);
}
}
