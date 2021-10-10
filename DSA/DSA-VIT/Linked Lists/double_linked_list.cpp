#include <bits/stdc++.h>
using namespace std;
int main() {
    list<int>l={1,2,3,4,5};

    //inserting
    l.push_front(6);

    for(auto x:l)
    cout<<x<<"->";
    cout<<"\n";

    //sorting
    l.sort();
    for(auto x:l)
    cout<<x<<"->";
    cout<<"\n";

    //reversing
    l.reverse();
    for(auto x:l)
    cout<<x<<"->";
    cout<<"\n";

    //deleting
    l.pop_front();
    for(auto x:l)
    cout<<x<<"->";
}
