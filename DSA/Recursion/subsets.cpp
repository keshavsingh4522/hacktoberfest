#include <bits/stdc++.h>
using namespace std;

void subset(char *inp,char *out,int i,int j)
{
    if(inp[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
    }

    //include the current char
    out[j]=inp[i];
    subset(inp,out,i+1,j+1);

    //exclude the current char
    subset(inp,out,i+1,j);
}

int main() {
    char input[]="abc";
    char output[10];

    subset(input,output,0,0);
}
