
// so what is the use of function template, it helps us to reduce the dependency over 
// overloaded functions, or multiple function for different data types

#include<iostream>
using namespace std;

template <class T2>
void swapp(T2 &a, T2 &b)
{
    T2 temp = a;
    a = b;
    b = temp;
}

template <class T1, class T2>
float funcAvg(T1 a, T2 b)
{
    float avg = (a+b)/2;
    return avg;
}
int main()
{
    float a = funcAvg<int, float>(5,2);
    cout<<a<<endl;

    char x = 'f',y = 'k';
    swapp<char>(x, y);
    cout<<x<<" "<<y; 
    return 0;
}
