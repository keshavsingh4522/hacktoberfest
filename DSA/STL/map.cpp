#include <bits/stdc++.h>
using namespace std;
int main() {
map<int,string>m;
m[0]="abc";
m[2]="xyz";
m[5]="sdf";
m.insert({3,"vgh"});

for(auto x:m)
cout<<x.first<<" "<<x.second<<endl;
  
}