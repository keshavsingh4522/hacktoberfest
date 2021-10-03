#include <iostream>

using namespace std;

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

string reverseWord(string str){

  int n = str.length();
  for(int i=0; i<n/2; i++){
      swap(str[i], str[n-i-1]);
  }
  
  return str;
}