#include <iostream>
#include "stackUsingLL.cpp"
using namespace std;


int main (){
    stack <int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1.getSize() << endl;
    s1.display();
    s1.pop();
    cout << s1.getSize() << endl;
    s1.display();
    
    stack <char> s2;
    s2.push('h');
    s2.display();
    return 0;
}