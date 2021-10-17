// list is a bidirectional linear list which is highly efficient in operations like insertion and deletion
// basicaly it is a special form of Linked list
#include<iostream>
#include<list>
using namespace std;

void display(list<int> &lst)
{
    list<int> :: iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout<<*it<<" ";
    }
    
}
int main()
{
    list<int> list1; // list of size 0 length
    
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(9);
    list1.push_back(12);
    list1.pop_back();
    list1.pop_front();
    list1.remove(9);
    list1.sort();
    display(list1);

    list<int> list2(4); // empty list of size 7 length
    list<int> :: iterator iter;
    iter = list2.begin();
    *iter = 45;
    iter++;
    *iter = 6;
    iter++;
    *iter = 9;
    iter++;
    *iter = 14;
    iter++;
    display(list2);
    list1.merge(list2);
    list1.reverse();
    display(list1);
    return 0;
}