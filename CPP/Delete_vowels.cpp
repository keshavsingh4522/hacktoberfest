//Program to delete all the vowels from a given string and print the resulting string 

#include<iostream>
#include<string>
using namespace std;

int main()
{
        string st,ans="";
        
        cout<<"\n Enter String : ";
        cin>>st;

        for(int i=0; i<st.size() ; i++)
        {
                if (tolower(st[i])!='a' && tolower(st[i])!='e' && tolower(st[i])!='i' && tolower(st[i])!='o' && tolower(st[i])!='u')
                
                ans+=st[i];
        }
        cout<<"\n String After Deleting Vowels : "<<ans;
        return 0;
}
