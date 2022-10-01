#include<iostream>
#include<vector>
using namespace std;
 void display(vector<int> &v)
    { // here v is a reference, we can use later (e.g v.size())
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<< " ";
        }cout<<endl;
    }
   
int main()
{
    // Declaration of Vector : vector<data_type> name;
    vector<int> vec1;
    int element;
    for(int i=0;i<4;i++)
    {
        cout<<"Enter Element\t"<<i<<" to add"<<"\t";
        cin>>element;
        vec1.push_back(element);
    }
    display(vec1);
    return 0;
}