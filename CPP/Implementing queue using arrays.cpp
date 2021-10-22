// Kaushal Barhate
// Implementing Queue using arrays

#include <iostream>
using namespace std;
class queue
{
    int rear, front;

public:
    int q[60];
    queue()
    {
        rear = front = -1;
    }
    int dequeue()
    {
        int temp;
        if (rear == -1 && front == -1)
        {
            return (-1);
        }
        else
        {
            if (front == rear)
            {
                temp = q[front];
                rear = -1;
                front = -1;
                return (temp);
            }
            else
            {
                return (q[front++]);
            }
        }
    }
    void enqueue(int x)
    {
        if (rear == -1 && front == -1)
        {
            rear = front = 0;
            q[rear] = x;
        }
        else
        {
            rear++;
            q[rear] = x;
        }
    }
    int peek()
    {
        if (rear == -1 && front == -1)
            return (-1);
        else
            return (q[front]);
    }
    int isempty()
    {
        if (rear == -1 && front == -1)
            return 1;
        else
            return 0;
    }
};

int main()
{
    queue q1;
    int n, inp, temp;
    cout << "Enter the number of elements ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        q1.enqueue(inp);
    }
    temp = q1.dequeue();
    q1.enqueue(temp);
    if (q1.isempty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            inp = q1.dequeue();
            cout << inp << " ";
        }
    }
}