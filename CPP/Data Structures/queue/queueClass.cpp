#include <iostream>
#include <climits>

using namespace std;

template <typename T>
class Queue {
    T *arr;
    int head, tail;
    int sz;
    int capacity;

    public:
    Queue(int capacity = 10) {
        this->capacity = capacity;
        sz = 0;
        head = 0;
        tail = 0;
        arr = new T[capacity];
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }

    bool full() {
        return sz == capacity;
    }

    void resize(int cap) {
        if(cap < 1) cap = 1;
        T* narr = new T[cap];

        for(int i=0; i<sz; i++) 
            narr[i] = arr[(head + i) % capacity];
        delete []arr;
        arr = narr;
        capacity = cap;
    }

    void enqueue(T value) {
        if (full()) {
            resize(2 * capacity);
        }
        arr[tail] = value;
        tail = (tail + 1) % capacity;
        sz++;
    }

    T dequeue() {
        if(empty()) {
            throw std::underflow_error("Queue is empty");
        }
        T val = arr[head];
        head = (head + 1) % capacity;
        sz--;
        return val;
    }

    T front() {
        if(empty()) {
            throw std::underflow_error("Queue is empty");
        }
        return arr[head];
    }

    void display() {
        for(int i=0; i<sz; i++) {
            cout << arr[(head + i) % capacity] << " ";
        }
        cout << endl;
    }

    ~Queue() {
        delete []arr;
    }

};