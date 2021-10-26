# include<iostream>
using namespace std;

int fact(float a){
    int f;
    if(a == 0)
        return 1;
    f = a;
    while(a>1){
        a=a-1;
        f = f*a;
    }
    return f;
}

int main()
{
int i,ncr,n,r;
cin>>n>>r;
ncr = fact(n)/(fact(r)*fact(n-r));
cout<<ncr;
return 0;
}