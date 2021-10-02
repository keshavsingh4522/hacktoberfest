#include <iostream>
#include "node.h"
#include <math.h>
using namespace std;

template <typename t>
class map {
    public:
    node <t> ** array;
    int count;
    int bucketSize;
    
    map(int bucketSize){
        this -> bucketSize = bucketSize;
        count = 0;
        array = new node<t>*[bucketSize];
        for (int i =0;i<bucketSize;i++){
            array[i] = NULL;
        }
    }
    
    ~map(){
        for (int i =0;i<bucketSize;i++){
            delete array[i];
        }
        delete [] array;
    }
    
    int size(){
        return count;
    }

    void insert(string key, t value){ // well done, yeh bc cn ulta kaam kr rhe, ulta add kr rhe linked list main
        int bucketIndex = getBucketIndex(key);
            node <t> * temp = array[bucketIndex];
            while (temp != NULL){
                if (temp -> key == key){
                    temp -> value = value;
                    return;
                }
                temp = temp -> next;
            }
            temp = array[bucketIndex];
            node <t> * newNode = new node<t>(key,value);
            newNode -> next = temp;
            array[bucketIndex] = newNode;
            count++;
    }
    
    t getValue(string key){
        int bucketIndex = getBucketIndex(key);
        node <t> * head = array[bucketIndex];
        while (head != NULL){
            if (head -> key == key){
                return head -> value;
            }
            head = head -> next;
        }
        return 0;
    }
    
    t removeKey(string key){
        int bucketIndex = getBucketIndex(key);
        cout << "bucketIndex for " << key << " is " << bucketIndex << endl;
        node <t> * head = array[bucketIndex];
        cout << "Key " << head -> key << endl;
        node <t> * prev = NULL;
        while (head != NULL){
            cout << "This is working";
          if (head -> key == key){
              if (prev == NULL){
                  array[bucketIndex] = head -> next;
                 
              }else{
                  prev -> next = head -> next;
              }
              cout << "This is working too";
              head -> next = NULL;
              t value = head -> value;
              delete head;
              count--;
              return value;
          }
          prev = head;
          head = head -> next;
        }
        return 0;
    }
    
    
    void display(){
        for (int i =0;i<bucketSize;i++){
            displayHelperFunction(array[i]);
        }
    }
    
    
    private:
    int getBucketIndex(string key){
        int hashcode;
        int currentCoefficient = 1;
        for (int i =0;i<key.length();i++){
            hashcode += currentCoefficient * key[i];
            hashcode = hashcode; // to avoid values going out of range
            currentCoefficient *=11;
            currentCoefficient % bucketSize;
        }
        return hashcode % bucketSize;
    } 
    void displayHelperFunction(node <t> * head){
        while(head != NULL){
            cout << "(" << head -> key << " , " << head -> value << ")" << endl; 
            head = head -> next;
        }
    }
};