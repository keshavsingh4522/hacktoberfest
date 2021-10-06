#include <bits/stdc++.h>
using namespace std;

int main()
{

  //random allocation is allowed...
  deque<int> dq;

  dq.push_back(1);
  dq.push_back(5);
  dq.push_back(6);

  dq.push_front(7);
  dq.push_front(9);

  for (auto it = dq.begin(); it != dq.end(); it++)
  {
    cout << *it;
  }
}