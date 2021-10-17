#include<iostream>
#include<vector>
using namespace std;

template <class T>
void display(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<float> vec1;
    float ele;
    int size;
    cout<<"Enter the size of vector: ";
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout<<"enter values to this vector"<<endl;
        cin>>ele;
        vec1.push_back(ele);
    }
    display(vec1);
    vector<float> :: iterator iter = vec1.begin();
    vec1.insert(iter+1,50, 566.6);
    display(vec1);
    return 0;
}