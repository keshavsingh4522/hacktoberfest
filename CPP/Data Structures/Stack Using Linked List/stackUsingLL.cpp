#include <iostream>
#include "nodeClass.cpp"
using namespace std;



template <typename t>
class stack{
    node <t> * head;
    node <t> * tail; 

    int length;
    
    public:
    stack(){
        head = NULL;
        tail = NULL;
        length = 0;
    }
    
    void push(t data){
        node <t> * newNode = new node<t>(data); 
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }else {
            tail -> next = newNode;
            tail = newNode;
        }
        length++;
    }
    
    t pop(){
        node <t> * temp = head;
        while (temp -> next != tail){
            temp = temp -> next;
        }
        t data = tail -> data;
        temp -> next = NULL;
        tail = temp;
        length--;
        return data;
    }
    
    void display(){
        node <t> * temp = head;
        while (temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }

    int getSize(){
        return length;
    }
    
};