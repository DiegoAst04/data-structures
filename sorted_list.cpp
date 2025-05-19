#include <iostream>
using namespace std;

struct node {
  int value;
  node* next = nullptr;

  node(int x) {
    value = x;
  }
};

class SortedList {
  node* head = nullptr;

public:
  bool find(int x, node**& p);
  void insert(int x);
  void remove(int x);
  void print();
};

bool SortedList::find(int x, node**& p ) {
  p = &head;
  while (*p && (*p)->value <= x) {
    if ((*p)->value == x) {
      return 1;
    }
    p = &((*p)->next);
  }
  return 0;
}

void SortedList::insert(int x) {
  node** p;
  if (!find(x, p)) {
    node* tmp = new node(x);
    tmp->next = *p;
    *p = tmp;
  }
}

void SortedList::remove(int x ) {
  node** p;
  if (find(x, p)) {
    node* tmp = *p;
    *p = (*p)->next;
    delete tmp;
  }
}

void SortedList::print() {
  for (node* p = head; p; p = p->next) {
    cout << p->value;
    if (p->next) {
      cout << ", ";
    }
  }
}

int main() {
  SortedList s;

  s.insert(3);
  s.insert(5);
  s.insert(4);
  s.insert(3);

  s.remove(5);

  s.print();
}