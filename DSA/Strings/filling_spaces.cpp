#include<iostream>
#include<string.h>
using namespace std;

int main ()

    {   
        char str[100];
        gets(str);

        for (int i = 0; str[i] !='\0'; i++)

        {
    	    if (str[i] == ' ')
              str[i]='%';
        }			

        cout<<str;
        return 0; 
    }