#include<bits/stdc++.h>
using namespace std;
//Robin carp string matching fuction

int ss(string s2 ,int l, int p)
{ int summ =0;
  int i=0;
  while(p--)
  {
      summ = summ*10 + (int)s2[l+i];
      i++;
  }
  return summ;
}

int main()
{   
    string s,r,n,m;
    int sum=0;
    int flag =0;
    cout<<"Enter String ";
    cin>>s;
    cout<<"Enter search string ";
    cin>>r;
    //n=r.length();
    //m=s.length();

    int k = ss(r,0,r.length());


    
    for(int i=0;i<(s.length()-r.length()+1);i++)
    {
        sum = ss(s,i,r.length());
        if(k == sum)
        {
            cout<<"String found";
            flag=1;
            break;
        }
    }

    if(!flag)
    cout<<"String not found";

    
    



    return 0;

}