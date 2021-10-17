// Custom class with a user defined Datatype.
// Now we will see class template with mutiple parameters
// till now we have seen that if we make a template then we can give a custom data type T.
// Suppose we want to make a template where we want to specify 2 data types.
// suppose we have to arrays inside a class, and we want to supply two different data types to it, 
// during object creation.

#include<iostream>
using namespace std;

template <class T1, class T2>
class myclass
{
    public:
        T1 data1;
        T2 data2;

        myclass(T1 a, T2 b)
        {
            data1 = a;
            data2 = b;
        }
        void display()
        {
            cout<<this->data1<<data2<<endl;
        }
};

int main()
{
    myclass <int, char> obj(1, 'c');

    obj.display();
    return 0;
}
