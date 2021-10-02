#include <iostream>
using namespace std;

template <typename v>
class node {
    public:
    
    v data;
    node * next;
    
    node(v data){
        this -> data = data;
        next = NULL;
    }
};
