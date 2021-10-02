#include <iostream>
#include <string>
using namespace std;
int main() {
    /*
   string para="my name is vashishth gajjar";
   string word;
   getline(cin,word);

    //returns the index
   cout<<para.find(word);*/

   //finding multiple occurences
   string big="i am big string,as big as hulk";
   string small="big";

   //1st occurence
   int found=big.find(small);
   cout<<found<<" ";

   //2nd ocurrence
   found=big.find(small,found+1);
   cout<<found;
   
}
