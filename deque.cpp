#include <iostream>
using namespace std;

struct node {
  int A[5] = {0};
  node* next = nullptr;
  node* prev = nullptr;
};

struct Deque {
  node* front = nullptr;
  node* back = nullptr;
  int* first = nullptr;
  int* last = nullptr;
  
  void pushFront(int x);
  void pushBack(int x);
  void popFront();
  void popBack();
  void print();
};

void Deque::pushFront(int x) {
  if (!front) {
    front = new node;
    back = front;
    first = front->A;
    *first = x;
    last = first;
    return;
  }
  if (last == front->A+4) {
    node* tmp = new node;
    front->next = tmp;
    tmp->prev = front;
    front = tmp;
    last = front->A;
    *last = x;
    return;
  }
  last++;
  *last = x;
}

void Deque::pushBack(int x) {
  if (!front) {
    front = new node;
    back = front;
    first = front->A;
    *first = x;
    last = first;
    return;
  }
  if (first == back->A) {
    node* tmp = new node;
    tmp->next = back;
    back->prev = tmp;
    back = tmp;
    first = back->A+4;
    *first = x;
    return;
  }
  first--;
  *first = x;
}

void Deque::popFront() {
  if (!front) {
    cout << "popFront: Deque vacio" << endl;
    return;
  }
  if (last == front->A) {
    node* tmp = front;
    front = front->prev;
    delete tmp;
    front->next = nullptr;
    last = front->A+4;
    return;
  }
  if (first == last) {
    delete front;
    front = nullptr;
    back = nullptr;
    first = nullptr;
    last = nullptr;
    return;
  }
  last--;
}

void Deque::print() {
  for (node* p = back; p; p = p->next) {
    if (p != back) {
      cout << " <=> ";
    }
    cout << "[";
    bool isFirstHere = first>=p->A && first<p->A+4;

    for (int* i = isFirstHere ? first : p->A; i < p->A+5 && last+1 != i; i++) {
      cout << *i;
      if (i != last && i != p->A+4) {
        cout << ", ";
      }
    }
    cout << "]";
  }
  cout << endl;
}

int main() {
  Deque dq;
  dq.pushFront(11);
  dq.pushBack(8);
  dq.popFront();
  dq.popFront();
  dq.print();
  cout << "first: " << *(dq.first) << endl;
  cout << "last: " << *(dq.last) << endl;
}