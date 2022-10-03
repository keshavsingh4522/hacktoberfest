#include <iostream>

using namespace std;

class SinglyLinkedListNode
{
public:
  int data;
  SinglyLinkedListNode *next;

  SinglyLinkedListNode(int node_data)
  {
    this->data = node_data;
    this->next = nullptr;
  }
};

class SinglyLinkedList
{
public:
  SinglyLinkedListNode *head;
  SinglyLinkedListNode *tail;

  SinglyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert_node(int node_data) {
    SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

    if (!this->head) {
      this->head = node;
    } else {
      this->tail->next = node;
    }

    this->tail = node;
  }
};

SinglyLinkedListNode *reverse(SinglyLinkedListNode *llist, SinglyLinkedListNode *prev = nullptr)
{
  SinglyLinkedListNode *next = llist->next;
  llist->next = prev;
  if (!next) return llist;
  return reverse(next, llist);
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    for (int i = 0; i < llist_count; i++) {
      int llist_item;
      cin >> llist_item;
      llist->insert_node(llist_item);
    }
    SinglyLinkedListNode *llist1 = reverse(llist->head);
    SinglyLinkedListNode *llist1Free = llist1;
    while (llist1) {
      cout << llist1->data;
      llist1 = llist1->next;
      if (llist1) {
        cout << " ";
      }
    }
    cout << "\n";

    while (llist1Free) {
      SinglyLinkedListNode *temp = llist1Free;
      llist1Free = llist1Free->next;
      free(temp);
    }
  }

  return 0;
}
