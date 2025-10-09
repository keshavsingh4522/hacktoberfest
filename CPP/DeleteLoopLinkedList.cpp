#include<iostream>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
};
 
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
void detectLoop(Node* head)
{
    Node *slow = head, *fast = head;
 
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if(slow==head){
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=NULL;

    }
    else if(slow == fast){
        slow=head;
        while(fast->next!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        fast->next=NULL;
    }
    
}
void printList(struct Node* node)
{
    // Print the list after loop removal
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
int main()
{
    Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    head->next->next->next->next = head;
    detectLoop(head);
    cout << "Linked List after removing loop \n";
    printList(head);
}