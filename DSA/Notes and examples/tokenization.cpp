#include <bits/stdc++.h>
using namespace std;
int main() {
    //tokenization- "hi i am a student"
    //"i","am","a","student" are tokens

    char arr[50]="i am a student";
    char *ptr;
    ptr=strtok(arr," ");

    while(ptr!=NULL)
    {
        cout<<ptr<<endl;
        ptr=strtok(NULL," ");
    }
}

