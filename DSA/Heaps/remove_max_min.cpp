#include <bits/stdc++.h>
using namespace std;

class heap{
    vector<int>v;
    bool minHeap;
    public:
    Heap(int size=10,bool type=true)
    {
        //vector won't expand till size exceeds 10
        v.reserve(size);

        //blocking 0th index
        v.push_back(-1);
        minHeap=type;
    }

    void insert(int d)
    {
         v.push_back(d);
         int idx=v.size()-1;
         int parent=idx/2;


         while(idx>1 and v[idx]>v[parent])
         {
             swap(v[idx],v[parent]);
             parent=idx;
             parent=parent/2;
         }
    }
};

int main() {
   
}
