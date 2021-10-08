#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

typedef struct numlist{
    int number;
    struct numlist *next;
}numlist;

void inserttochain(int key, numlist **head){
    numlist *ptr = (*head);
    numlist *node = (numlist*)malloc(sizeof(numlist));
    node->number = key;
    node->next = NULL;

    if(*head == NULL){
        *head = node;
    }
    else{
        while(ptr->next !=NULL){
            ptr = ptr->next;
        }
        ptr->next = node;
    }

}

int main(){
    numlist *hasht[10];
    int i;
    for(i=0; i<10; i++){
        hasht[i]=NULL;
    }
    while(1){
        system("cls");
        for(i=0; i<10; i++){
            numlist *ptr = hasht[i];
            printf("[%d]->",i);
            while(ptr!=NULL){
                printf("(%d)",ptr->number);
                ptr = ptr->next;
            }
            printf("\n");
        }
        int inputkey;
        scanf("%d",&inputkey);
        inserttochain(inputkey, &hasht[inputkey%10]);
    }
    return 0;
}