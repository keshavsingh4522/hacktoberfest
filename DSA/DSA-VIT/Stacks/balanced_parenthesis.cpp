#include <bits/stdc++.h>
using namespace std;

bool check(char *ch)
{
    stack<char>s;
    for(int i=0;ch[i]!='\0';i++)
    {
        if(ch[i]=='(')
        s.push(ch[i]);
        else if(ch[i]==')')
        {
            if(s.empty() || s.top()==')')
            return false;
        }
        s.pop();
    }
    return true;
}

int main() {
    char ch[10000]="(())";
    if(check(ch))
    cout<<"imbalanced parenthesis";
    else
    cout<<"balanced parenthesis";
}

