//Program to delete all the vowels from a given string and print the resulting string 

#include<iostream>
using namespace std;

int main()
{
        char str[100];
        cout<<"\n Enter String : ";
        cin>>str;

        for(int i=0; str[i]!='\0'; i++)
        {
                if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I'
|| str[i]=='O' || str[i]=='U')
                {
                        str[i]=' ';
                }
        }
        cout<<"\n String After Deleting Vowels : "<<str;
        return 0;
}
