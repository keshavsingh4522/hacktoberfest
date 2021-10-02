//This Program is for Infix to Postfic conversion
//It is important to rememeber coversion to Postfix depends on bnoth precedence and Associativity(L-R or R-L)
//of operators...
//Conversion can be postfix, or prefix
//Infix : operand operator operand
//Postfix : operand operand operator
//Prefix : operator operand operand

//There are 2 Methods for Infix to Postfix Conversion, both using stacak
//We will be looking at both of them

//Method 1
//if operand is encountered simply print the operand
//if operator is encountered push it into stack
//Before pushing check the stack for other operators precedence
//if precedence of operators in stack less than that of new operator simply push the ne operator
//else pop till the precedence of operator becomes less than the new operator or the stack is empty
//push the new operator
//This goes on till end of the exp
//At end of exp pop out and add all the operators present in stakc to postfix operation

//Method 2
//Similar to Method 1 except in this case we are also pushing the operand
//All the operations are similar...
//Important : The Operands should have higher precedence

#include <iostream>
#define endl "\n"
using namespace std;

//First thing we require is a Stack
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
    Stack(){top = NULL;}
    ~Stack();
    void push(T x);
    T pop();
    bool isEmpty();
    T StackTop();
};

template <class T>
Stack<T> :: ~Stack(){
    Node<T> *p;
    while(top){
        p = top;
        top = top->next;
        delete p;
    }
    top = NULL;
}

template<class T>
void Stack<T> :: push(T x){
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
    Node<T> *p;
    if(top == NULL)
        cout << "Stack Underflow\n";
    else{
        p = top;
        top = top->next;;
        x = p->data;
        delete p; 
    }
    return x;
}

template <class T>
T Stack<T> :: StackTop(){
    if(top == NULL)
        return -1;
    return top->data;
}

template <class T>
bool Stack<T> :: isEmpty(){
    return top == NULL;
}
//Stack portion complete

//Method 1
bool isOperand(char x){
    string operators = "+-*/";
    for(int i=0; operators[i] != '\0'; i++){
        if(x == operators[i])
            return false;
    }
    return true; 
}

int pre(char x){
    if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    return 0;
}

int len(char *p){
    int i;
    for(i = 0; p[i] != '\0'; i++);
    return i;
}

char* IntoPos(char *infix){
    Stack<char> st;
    
    char *postfix = new char[len(infix) + 1];
    int i=0, j=0;;
    while(infix[i] != '\0'){
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if(st.StackTop() == -1 || pre(infix[i]) > pre(st.StackTop()))
                st.push(infix[i++]);
            else
                postfix[j++] = st.pop();
        }
    }
    while(!st.isEmpty()) postfix[j++] = st.pop(); 
    postfix[j] = '\0';
    return postfix;
}

//Method2
int pre2(char x){
    if(x == '/' || x == '*')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else return 3;
}

char* IntoPos2(char* infix){
    Stack<char> st;
    char *postfix = new char[len(infix) + 1];
    int i=0, j=0;
    while(infix[i] != '\0'){
        if(st.isEmpty() || pre2(infix[i]) > pre2(st.StackTop()))
            st.push(infix[i++]);
        else
            postfix[j++] = st.pop();
    }
    while(!st.isEmpty()) postfix[j++] = st.pop();
    postfix[j] = '\0';
    return postfix;
}

int main(){
    cout << "Enter an Expression : ";
    char infix[20];
    scanf("%s", infix);
    printf("%s", IntoPos2(infix));

    return 0;
}