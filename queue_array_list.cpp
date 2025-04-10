#include <iostream>
using namespace std;

template <class T>
struct node {
  T A[5];
  node* next;

  node(node* n) {
    next = n;
  }
};

template <class T>
class Queue {
  node<T>* front = nullptr;
  node<T>* back = nullptr;
  int* first = nullptr;
  int* last = nullptr;
public:
  void push(T x);
  void pop();
  void print();
};

template <class T>
void Queue<T>::push(T x) {
  if (!back) {
    back = new node<T>(nullptr);
    front = back;
    first = back->A;
    last = first;
    *last = x;
    return;
  }
  if (last == back->A+4) {
    back->next = new node<T>(nullptr);
    back = back->next;
    last = back->A;
    *last = x;
    return;
  }
  last++;
  *last = x;
}

template <class T>
void Queue<T>::pop() {
  if (!front) {
    return;
  }
  if (first == last) {
    delete front;
    front = back = nullptr;
    first = last = nullptr;
    return;
  }
  first++;
  if (first == front->A+5) {
    node<T>* tmp = front;
    front = front->next;
    first = front->A;
    delete tmp;
  }
}

template <class T>
void Queue<T>::print() {
  for (node<T>* p = front; p; p=p->next) {
    cout << "[";
    bool isFirstHere = (first >= p->A) && (first <= p->A+4);
    for (int* i = isFirstHere ? first : p->A; (i<=p->A+4) && (i != last+1); i++) {
      cout << *i;
      if ((i != last) && (i != p->A+4)) {
        cout << ", ";
      }
    }
    cout << "]";
    if (p->next) {
      cout << "->";
    } 
  }
}

int main() {
  Queue<int> q;
  q.push(4);
  q.push(5);

  q.pop();

  q.print();
}