#include <iostream>
#include <string>
using namespace std;
void printPermutationsHelper(string input, string output){ 
    if(input.length() == 0){
        cout << output << endl; 
        return;
    }
    for(int i = 0; i< input.length(); i++){
        char ch=input[i];
        string lstr=input.substr(0,i);
        string rstr=input.substr(i+1);
        string str=lstr+rstr;
        printPermutationsHelper(str,output+ch);
    }
}
void printPermutations(string input){ 
    printPermutationsHelper(input, "");
    return;
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}