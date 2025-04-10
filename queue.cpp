#include <iostream>
using namespace std;

template <class T>
struct node {
  int value;
  node<T>* next;

  node(int value, node* next) {
    this->value = value;
    this->next = next;
  }
};

template <class T>
struct Queue {
  node<T>* first = nullptr;
  node<T>* last = nullptr;

  void push(T x);
  void pop();
  void print();
  void clear();
};

template <class T>
void Queue<T>::push(T x) {
  if (!first) {
    first = new node<T>(x, nullptr);
    last = first;
    return;
  }
  node<T>* tmp = last;
  last = new node<T>(x, nullptr);
  tmp->next = last;
}

template <class T>
void Queue<T>::pop() {
  if (!first) {
    cout << "Pop: Cola vacía";
    return;
  }
  node<T>* tmp = first;
  first = first->next;
  delete tmp;
}

template <class T>
void Queue<T>::print() {
  cout << "First -> ";
  for (node<T>* p = first; p; p = p->next) {
    cout << p->value << " -> ";
  }
  cout << "Last";
}

template <class T>
void Queue<T>::clear() {
  while (first) {
    pop();
  }
}

int main() {
  Queue<int> queue;
  queue.push(5);
  queue.push(15);
  queue.push(25);
  queue.push(35);
  queue.clear();
  queue.push(50);
  queue.print();
}