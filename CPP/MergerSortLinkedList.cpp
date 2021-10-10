/*Merge Sort for Linked List 
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.
Example 1:
Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
Example 2:
Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.
Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)
 */
#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
void push(node** head, int l_data){
    node* temp = new node();
    temp->data = l_data;
    temp->next=NULL;
    if(*head == NULL){
        *head = temp;
        return;
    }
    node*n = *head;
    while(n->next!=NULL)
        n = n->next;
    n->next=temp;
}
void findMiddleElement(node* curr, node**first, node**second){
    node* slow= curr;
    node* fast = curr->next;
    while(fast!=NULL){
        fast=fast->next;
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }

    *first = curr;
    *second = slow->next;
    slow->next=NULL;
}

node* mergeBoth(node* first, node* second){
    node* answer = NULL;
    if(!first)
        return second;
    if(!second)
        return first;

    if(first->data <= second->data){
        answer = first;
        answer->next = mergeBoth(first->next, second);
    }else{
        answer = second;
        answer->next = mergeBoth(first, second->next);
    }
    return answer;
}

void  MergeSorting(node**head){
    node* curr= *head;
    node* first;
    node* second;
    if(!curr || !curr->next) return;

    findMiddleElement(curr, &first, &second);

    MergeSorting(&first);
    MergeSorting(&second);
    *head = mergeBoth(first, second);
}
node* mergeSort(node* head){
    MergeSorting(&head);
    return head;
}
void print(node* n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<"\n";
}
int main(){
    node* head = NULL;
    int n, ele;
    cout<<"\n Enter the size of the llist : ";
    cin>>n;
    cout<<"\n Enter elements to be entered in linked list: ";
    for(int i=0; i<n; i++){
        cin>>ele;
        push(&head, ele);
    }
    cout<<"\n The llist 1 is: ";
    print(head);
    head = mergeSort(head);
    cout<<"\n merge sort of ll: ";
    
    print(head);
}