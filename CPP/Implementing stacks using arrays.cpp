// Kaushal Barhate
// Implementing stacks using arrays

#include <iostream>
using namespace std;
class stack
{
    int top;

public:
    int sk[100];
    stack()
    {
        top = -1;
    }
    void push(int x)
    {
        if (top >= 10)
            cout << "Stack full" << endl;
        else
        {
            if (top == -1)
            {
                top = 0;
                sk[top] = x;
            }
            else
            {
                top++;
                sk[top] = x;
            }
        }
    }
    void pop()
    {
        if (top == -1)
            cout << "Stack empty" << endl;
        else
        {
            cout << "Popped element is: " << sk[top] << endl;
            top--;
        }
    }
    void peek()
    {
        cout << "\nTop most element is (peek): " << sk[top] << endl;
    }
};
int main()
{
    int inp;
    stack s;
    int n;
    cout << "Enter number of elements to be pushed" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        s.push(inp);
    }
    s.peek();
    for (int i = 0; i < n; i++)
    {
        s.pop();
    }
    s.peek();
}
