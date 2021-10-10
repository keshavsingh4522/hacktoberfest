#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[100];
    gets(s);

    //splitting the string wrt delimiters (ex: "-"," ","/")
    char *token=strtok(s," ");

    while(token!=NULL)
    {
        cout<<token<<endl;
        token=strtok(NULL," ");
    }
}
