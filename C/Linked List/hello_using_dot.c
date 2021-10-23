//Print HELLO using dot operator->it uses to access character directly 
#include<stdio.h>

struct node{
    char info;
    struct node *next;
};
int main()
{
    struct node temp1,temp2,temp3,temp4,temp5;
    temp1.info='H';
    temp1.next=NULL;
    printf("%c",temp1.info);

    temp2.info='E';
    temp2.next=NULL;
    printf("%c",temp2.info);

    temp3.info='L';
    temp3.next=NULL;
    printf("%c",temp3.info);

    temp4.info='L';
    temp4.next=NULL;
    printf("%c",temp4.info);

    temp5.info='O';
    temp5.next=NULL;
    printf("%c",temp5.info);
     return 0;
}
