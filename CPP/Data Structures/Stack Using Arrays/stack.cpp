#include <iostream>
#include "stackClass.cpp"
using namespace std;

// dynamic stack, changes it size acc to input

int main (){
    stack <int> s1(5);
    for (int i=0;i<5;i++){
        s1.push(i+1);
    }
    s1.display();
    stack <char> s2(5);
    s2.push('h');
    s2.display();
    
    s1.push(6);
    s1.push(7);
    s1.display();
    cout << s1.getSize();
    cout << endl;
    stack <int> s3; 
    cout << s3.getSize();
    return 0;
}