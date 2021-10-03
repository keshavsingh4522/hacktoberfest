#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // empty map container
    map<string, int> marks;
     // insert elements in random order
    marks["Shreya"] = 98;
    marks["Neha"] = 59;
    marks["Jack"] = 2;

    // insert in map
    marks.insert({"Suzy",88});
    marks.insert({"Gerald",95});

     // printing map marksMap
    map<string, int> :: iterator iter;
    for(iter=marks.begin(); iter != marks.end(); iter++){
        cout<<(*iter).first<<" "<<(*iter).second<<endl;
    }

    //print size of map
    cout<<"The size is: "<<marks.size()<<endl;

    // remove element with key = shreya
    string ch;
    ch = marks.erase("Shreya");
    map<string, int> :: iterator iter2;
    for (iter2 = marks.begin(); iter2 != marks.end(); ++iter2) {
        cout<<(*iter2).first<<" "<<(*iter2).second<<endl;
    }

return 0;
}
