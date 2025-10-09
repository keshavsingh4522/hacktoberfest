#include <iostream>
#include<climits>
using namespace std;

template <typename t>
class stack {
    t * p;
    int top;
    int size;
    public :
    
    stack(int size = 10){
        top = -1;
        this -> size = size;
        p = new t[size];
    }
    
    int getSize(){
        return size;
    }
    
    int getTop(){
        return top;
    }
    
    bool isEmpty(){
        if (top == -1){
            return true;
        }else {
            return false;
        }
    }
    
    bool isFull(){
        if (top == size - 1){
            return true;
        }else {
            return false;
        }
    }
    
    void push(int data){
        if (isFull()){
            t * a = new t[size*2];
            int i;
            for (i=0;i<size;i++){
                a[i] = p[i];
            }
            top = i;
            a[top] = data;
            delete [] p;
            p = a;
            size = size * 2;
        }else{
            top++;
            p[top] = data;
        }
       
    }
    int pop(){
        if (isEmpty()){
            cout << "Stack is Empty" << endl;
            return 0;
        }else {
            int x = p[top--];
            return x;
        }
    }
    
    void display(){
        for (int i =0; i<top+1;i++){
            cout << p[i] << " ";
        }cout << endl;
    }
};