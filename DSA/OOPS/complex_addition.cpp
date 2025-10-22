#include <iostream>
using namespace std;

class Complex
{
    public:
    int real,img;
};

int main()
{
    Complex c1,c2,sum;
    c1.real=2,c1.img=3;
    c2.real=5,c2.img=4;

    sum.real=c1.real+c2.real;
    sum.img=c1.img+c2.img;

    cout<<sum.real<<"+"<<sum.img<<"i";
    return 0;
}

