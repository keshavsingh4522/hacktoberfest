#include<iostream>
#include <string>
using namespace std;

template <typename t>
class node {
    public:
    string key;
    t value;
    node <t> * next;
    
    node(string key,  t value){
        this -> key = key;
        this -> value = value;
        next = NULL;
    }
    
    ~node(){
        delete next;
    }
};