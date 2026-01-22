#include <bits/stdc++.h>
using namespace std;
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)


// <iostream>: This library provides input/output functionality, including reading from and writing to the standard input/output streams (cin, cout, cerr, etc.).

// <vector>: This library provides the vector container class, which is a dynamic array that can grow and shrink in size. It is a versatile container for storing and manipulating sequences of elements.

// <string>: This library provides the string class, which is used for working with strings of characters. It offers various string manipulation operations, such as concatenation, comparison, substring extraction, etc.

// <algorithm>: This library provides a collection of useful algorithms, such as sorting, searching, and manipulating elements in containers. It includes functions like sort(), find(), reverse(), and more.

// <cmath>: This library provides mathematical functions and constants, including basic arithmetic operations, trigonometric functions, logarithmic functions, etc.

// <fstream>: This library provides functionality for file input/output operations. It allows reading from and writing to files using file streams (ifstream, ofstream, fstream).

// <ctime>: This library provides functions and types for working with time and date, including obtaining the current time, formatting time and date strings, and performing various time-related calculations.

// <cstdlib>: This library provides general-purpose functions and types, including memory management functions (malloc(), free()), random number generation functions (rand(), srand()), and other utility functions.



class node
{
public:
  int value;
  node *next;
  node(int data)
  {
    value = data;
    next = nullptr;
  }
};

// In C++, when you pass a parameter to a function, you have two options: pass by value or pass by reference.

// Passing by value (using node *head):

// In this case, the function receives a copy of the pointer to the head of the linked list.
// If you modify the parameter inside the function, it will only affect the local copy of the pointer, not the original pointer outside the function.
// Therefore, if you modify the head pointer inside the insert function (e.g., by making it point to a new node), it won't have any effect on the original head pointer passed from the calling function.
// Passing by reference (using node *&head):

// In this case, the function receives a reference to the original pointer to the head of the linked list.
// If you modify the parameter inside the function, it will directly affect the original pointer outside the function.
// Therefore, if you modify the head pointer inside the insert function (e.g., by making it point to a new node), it will change the head pointer in the calling function as well.
// In the provided insert function, *&head is used because it needs to modify the head pointer (e.g., when inserting a new node at the beginning of the list or when the list is empty). If you used *head (pass by value), any changes to head inside the function would not affect the original head pointer.

// If you encountered an error when using only head, it might be due to how the function is called or used in the context of the code. Without seeing the complete code and the specific error message, it's challenging to pinpoint the exact issue. However, if you are using the insert function to modify the head pointer (e.g., inserting at the beginning), you need to use *&head to ensure the changes are reflected outside the function.


void insert(node *&head, int data, int pos)
{
  node *nw = new node(data);
  if (pos == 0)
  {
    nw->next = head;
    head = nw;
    return;
  }

  node *prev = head;

  for (int i = 0; i < pos - 1; i++)
  {
    prev = prev->next;
    cout<<"hi"<<endl;
  }
 
//  pehle newValue ko apni linked list se jodege...
  nw->next = prev->next;
  //  fr uske bad todege...
  prev->next = nw;
}

void delete_node(node *&head, int pos)
{
  if (pos == 0)
  {
    node *temp = head;
    head = head->next;
    free(temp);
    return;
  }

  node *prev = head;

  for (int i = 0; i < pos - 1; i++)
  {
    prev = prev->next;
  }

  node *toDelete = prev->next;
  prev->next = prev->next->next;
  delete toDelete;
}

int main()
{
  node *pc = new node(10);

  node *head = pc;

  f1(i, 5)
  {
    pc->next = new node(i);
    pc = pc->next;
  }

  node *current = head;

  while (current)
  {
    cout << current->value << " ";
    current = current->next;
  }
  cout << endl;
  insert(head, 100, 1);
  current = head;
  while (current)
  {
    cout << current->value << " ";
    current = current->next;
  }
  cout << endl;
  // delete_node(head, 4);
  // current = head;
  // while (current)
  // {
  //   cout << current->value << " ";
  //   current = current->next;
  // }

  // // delete_node()

  // // cleanup memory...
  // current = head;
  // while (current)
  // {
  //   node *temp = current;
  //   current = current->next;
  //   delete temp;
  // }

  return 0;
}
