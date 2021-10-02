#include <iostream>
#include "hashmapClass.h"
#include <string>
using namespace std;


int main (){
    map <int> ourmap(13);
    string key;
    int value;
    cout << "Enter key (Enter 0 for termination) : ";
    cin >> key;
    while (key != "0"){
        cout << "Enter Value of " << key << " : ";
        cin >> value;
        ourmap.insert(key,value);
        cout << "Enter another key (Enter 0 for termination) : ";
        cin >> key;
    }
    cout << endl;
    ourmap.display();
    
    ourmap.removeKey("Gopal");
    cout << "List after removing key" <<  endl;
    ourmap.display();
    return 0;
}