#include <iostream>
using namespace std;

int power(int base,int exp)
{
    if(exp==0)
    return 1;
    else
    return base*power(base,exp-1);
}

int main() {
    int base,exp;
    cin>>base>>exp;

    cout<<power(base,exp);
}
