#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node *next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void printList(struct Node *head){

    struct Node *p = head;

    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

Node *addTwoList(struct Node *first ,struct Node *second){

    Node *ptr1 = first;
    Node *ptr2 = second;
    Node *head = NULL;
    Node *cur = NULL;

    while(ptr1 and ptr2){

        if(ptr1->data==ptr2->data){
            if(head==NULL){
                Node *temp = new Node(ptr1->data);
                head=temp;
                cur=temp;
            }else{
                Node *temp = new Node(ptr1->data);
                cur->next=temp;
                cur=cur->next;
            }
            
            ptr1=ptr1->next;
            ptr2=ptr2->next;

        }else{
            if(ptr1->data < ptr2->data){
                ptr1=ptr1->next;
            }else{
                ptr2=ptr2->next;
            }
        }

    }

    return head;

}

int main(){
    
    
    Node* first = new Node(1);
    first->next = new Node(2);
    first->next->next = new Node(3);
    first->next->next->next = new Node(4);
    first->next->next->next->next = new Node(6);
    
    Node* second = new Node(2);
    second->next = new Node(4);
    second->next->next = new Node(6);
    second->next->next->next = new Node(8);

    cout<<"First list = ";
    printList(first);

    cout<<"\nSecond list = ";
    printList(second);

    Node *ans = addTwoList(first ,second);

    cout<<"\nIntersection Of two Lists = ";

    printList(ans);
    

    return 0;
}
