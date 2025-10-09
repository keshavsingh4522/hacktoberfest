#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

        ~Node(){
            cout << "Node : " << data << " removed" << endl;
        }
};

// Functions that require the pointer to the object only
bool isEmpty(Node *head){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

void printList(Node *head){
    Node *temp = head;
    if(isEmpty(head)){
        cout << "List is empty" << endl;
    }
    for(int i = 0; temp != NULL; i++){
        if(temp->next == NULL){
            cout << temp->data;
            temp = temp->next;
        }
        else{
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
    cout << endl;
}

Node* get_tail(Node *head){
    Node* temp_node;
    temp_node = head;
    while(temp_node->next != NULL){
        temp_node = temp_node->next;
    }
    return temp_node;
}

void deleteAll(Node **head){
    Node *temp = *head;
    for(int i = 0; temp != NULL; i++){
        Node *temp_t = temp;
        delete(temp);
        temp = temp_t->next;
    }
    *head = NULL;
}

void insert_after(int data, Node *head){
    // Search node
    int new_data;
    cout << "Enter value of the new node:" << endl;
    cin >> new_data;

    // if head is null
    if(isEmpty(head)){
        cout << "List is empty" << endl;
        return;
    }

    Node *temp_node = head;
    for(int i = 0; temp_node != NULL; i++){
        if(temp_node->data == data){
            // Found the node 

            // Storing the next node
            Node *next_node = temp_node->next;

            // Creating node
            Node *new_node = new Node();

            // Putting the next node on the new node 
            new_node->next = next_node;

            // Data of the new_node
            new_node->data = new_data;

            // the current node needs its next to be updated
            temp_node->next = new_node;
        }
        temp_node = temp_node->next;
    }
}

void index(int data, Node *head){
    Node *temp_node = head;
    
    // check if list is empty
    if(isEmpty(head)){
        cout << "List is empty" << endl;
        return;
    }

    bool found = false;
    int index = 0;
    while(temp_node != NULL){
        if(temp_node->data == data){
            found = true;
            cout << "Found it at: " << index << endl;
            return;
        }
        index++;
        temp_node = temp_node->next;
    }
}

// Require the reference of the pointer storing the pointer to the object
void init_list(Node **head){
    Node* temp_node = NULL;
    int data;
    int size;

    cout << "Enter the size of the list " << endl;
    cin >> size;

    cout << "Enter the node 1" <<endl;
    cin >> data;
    (*head) = new Node();
    (*head)->data = data;

    temp_node = *head;

    for(int i = 1; i < size; i++){
        Node *temp = new Node();
        cout << "Enter the node " << i+1 << endl;
        cin >> data;

        // updating the new node with data
        temp->data = data;
        temp->next = NULL;

        // Updating the previous node
        temp_node->next = temp;

        // changing the temp_node
        temp_node = temp;
    }
}


void push_front(Node **head){
    // if empty
    if(isEmpty(*head)){
        Node *newNode = new Node();
        newNode->next = NULL;
        cout << "Enter the data of new node:" << endl;
        cin >> newNode->data;
        *head = newNode;
        return;
    }
    
    Node *next_to_head;
    // Copying head to the next element of the new head
    next_to_head = *head;

    // creating a new head
    Node *new_head = new Node();
    int data;
    cout << "Enter the data of the new node: " << endl;
    cin >> data;
    
    new_head->data = data;
    new_head->next = next_to_head;
    *head = new_head;
}

void push_back(Node **head){

    // if list empty
    if(isEmpty(*head)){
        Node *new_head = new Node();
        int data;
        cout << "Enter the data of the new node: " << endl;
        cin >> data;
        new_head->data = data;
        new_head->next = NULL;
        *head = new_head;
        return;
    }

    Node *tail_node = get_tail(*head);
    Node *new_node = new Node();
    
    int data;
    cout << "Enter the new node data" << endl;
    cin >> data;
    
    new_node->data = data;
    tail_node->next = new_node;
}

void insert_before(int data, Node **head){
    // insert node before the node with data
    int new_data;
    cout << "Enter value of the new node:" << endl;
    cin >> new_data;

    Node *temp_node = *head;
    Node *prev_node = NULL;

    // if head is null
    if(isEmpty(*head)){
        cout << "List is empty" << endl;
        return;
    }

    // if the data is in the head
    if((*head)->data == data){
        // push front
        push_front(head);
        return;
    }
    for(int i = 0; temp_node != NULL; i++){
        if(temp_node->data == data){
            // Found the node
            // Creating node
            Node *new_node = new Node();

            // Putting the next node on the new node
            new_node->next = temp_node;
            
            // Data of the new_node
            new_node->data = new_data;

            // the previous node needs its next to be updated
            prev_node->next = new_node;
        }
        prev_node = temp_node;
        temp_node = temp_node->next;
    }    
}

void delete_head(Node **head){
    Node *nextNode = (*head)->next;
    delete(*head);
    *head = nextNode;
}

void delete_tail(Node **head){
    Node *temp_node = *head;
    Node *prev_node = NULL;

    // if head is the tail
    if(temp_node->next == NULL){
        delete(temp_node);
        *head = NULL;
        return;
    }

    while(temp_node->next != NULL){
        prev_node = temp_node;
        temp_node = temp_node->next;
    }
    prev_node->next = NULL;
    delete(temp_node);
}

void delete_node(int data, Node **head){
    Node *temp_node = *head;
    Node *prev_node = NULL;

    while(temp_node != NULL){
        if(temp_node->data == data){
            //check if temp_node is the head
            if(prev_node == NULL){
                // This is a head
                *head = temp_node->next;
                delete temp_node;
                temp_node = *head;
                return;
            }
            else{
                // This is not head
                prev_node->next = temp_node->next;
                delete temp_node;
                temp_node = prev_node->next;
            }
        }
        else{
            prev_node = temp_node;
            temp_node = temp_node->next;
        }
    }
}

int main(){
    Node* head = NULL;
    int data;
    int choice;

    // Menu driven program 
    while(1){
        cout << "1. Initialize the list" << endl;
        cout << "2. Display the list" << endl;
        cout << "3. Insert at the front" << endl;
        cout << "4. Insert at the back" << endl;
        cout << "5. Insert before a node" << endl;
        cout << "6. Insert after a node" << endl;
        cout << "7. Delete the head" << endl;
        cout << "8. Delete the tail" << endl;
        cout << "9. Delete a node" << endl;
        cout << "10. Search for a node" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch(choice){
            case 1:
                init_list(&head);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                push_front(&head);
                break;
            case 4:
                push_back(&head);
                break;
            case 5:
                cout << "Enter the data of the node: " << endl;
                cin >> data;
                insert_before(data, &head);
                break;
            case 6:
                cout << "Enter the data of the node: " << endl;
                cin >> data;
                insert_after(data, head);
                break;
            case 7:
                delete_head(&head);
                break;
            case 8:
                delete_tail(&head);
                break;
            case 9:
                cout << "Enter the data of the node: " << endl;
                cin >> data;
                delete_node(data, &head);
                break;
            case 10:
                cout << "Enter the data of the node: " << endl;
                cin >> data;
                index(data, head);
                break;
            case 11:
                deleteAll(&head);
                exit(0);
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}