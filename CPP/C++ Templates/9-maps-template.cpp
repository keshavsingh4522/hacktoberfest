
// Map is same like dictionary in python
#include<iostream>
#include<map>
#include<string>

using namespace std;
int main()
{
    map<string, int> marksmap;
    marksmap["Namit"] = 98;
    marksmap["havna"] = 78;
    marksmap["Rohan"] = 35;
    map<string, int> ::iterator iter;
    for (iter = marksmap.begin(); iter != marksmap.end() ; iter++)
    {
        cout<<(*iter).first<<" "<<(*iter).second<<"\n";
    }
    
    return 0;
}