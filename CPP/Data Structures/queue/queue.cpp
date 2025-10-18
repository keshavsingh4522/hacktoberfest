#include <iostream>
#include "queueClass.cpp"

using namespace std;

// dynamic queue, changes its size according to input

int main() {
    Queue<int> q1(5);
    for (int i = 0; i < 5; i++) {
        q1.enqueue(i + 1);
    }
    cout << "Dequeued: " << q1.dequeue() << endl;
    cout << "Dequeued: " << q1.dequeue() << endl;
    q1.enqueue(6);
    q1.enqueue(7);
    while (!q1.empty()) {
        cout << "Dequeued: " << q1.dequeue() << endl;
    }
    cout << "Current size of queue: " << q1.size() << endl;

    Queue<char> q2(5);
    q2.enqueue('h');
    q2.enqueue('e');
    q2.enqueue('l');
    q2.enqueue('l');
    q2.enqueue('o');
    while (!q2.empty()) {
        cout << "Dequeued: " << q2.dequeue() << endl;
    }

    return 0;
}