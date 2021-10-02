//This is an extension to the earlier Infix to Postfix conversion
//This takes into consideration both Brackets and Associativity(R-L or L-R) in addition to Order of precedence
//Here we make use of an Outer and and Inner Precedence
//And use Inner precedence for those inside Stack and Outer Precedence for those currently outside Stack

#include <iostream>
#define endl "\n"
using namespace std;

//Stack implementation
template <class T>
class Node{
    public:
    T data;
    Node *next;
};

template <class T>
class Stack{
    private:
    Node<T> *top;

    public:
    Stack(){top == NULL;}
    ~Stack();
    void push(T x);
    T pop();
    T StackTop();
    bool isEmpty();
};

template <class T>
Stack<T> :: ~Stack(){
    Node<T> *p;
    while(top){
        p = top;
        top = top->next;
        delete top;
    }
    top = NULL;
}

template <class T>
void Stack<T> :: push(T x)
{
    Node<T> *t = new Node<T>;
    if(t == NULL)
        cout << "Stack Overflow\n";
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

template <class T>
T Stack<T> :: pop(){
    T x = -1;
    if(top == NULL)
        cout << "Stack Underflow\n";
    else{
        Node<T> *p = top;
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;
}

template <class T>
T Stack<T> :: StackTop()
{
    if(top == NULL)
        return -1;
    else return top->data;
}

template <class T>
bool Stack<T> :: isEmpty(){
    return top == NULL;
}
//Stack complete

bool isOperand(char x){
    string oper = "+-*/^()";
    for(int i=0; oper[i] != '\0'; i++){
        if(x == oper[i])
            return false;
    }
    return true;
}

int preOuter(char x){
    if(x == '^')
        return 6;
    else if(x == '*' || x == '/')
        return 3;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '(')
        return 7;
    else if(x == ')')
        return 0;
    return -1;
}

int preInner(char x)
{
    if(x == '^')
        return 5;
    else if(x == '*' || x == '/')
        return 4;
    else if(x == '+' || x == '-')
        return 2;
    else if(x == '(')
        return 0;
    return -1;
}

int Length(char *p){
    int i;
    for(i=0; p[i]!='\0'; i++);
    return i;
}

char* IntoPost(char* infix){
    Stack<char> st;
    char *postfix = new char[Length(infix) + 1];
    int i=0, j =0;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if(st.isEmpty() || (preOuter(infix[i]) > preInner(st.StackTop())))
                st.push(infix[i++]);
            else if(preOuter(infix[i]) == preInner(st.StackTop())){
                st.pop();
                i++;
            }
            else 
                postfix[j++] = st.pop();
        }
    }
    while(!st.isEmpty()) postfix[j++] = st.pop();
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char a[20];
    cout << "Enter the Expression : ";
    scanf("%s", a);

    printf("Postfix Expression : %s", IntoPost(a));
    return 0;
}
