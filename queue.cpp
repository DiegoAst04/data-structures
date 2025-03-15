#include <iostream>
using namespace std;

struct node {
  int value;
  node* next;

  node(int value, node* next) {
    this->value = value;
    this->next = next;
  }
};

struct Queue {
  node* first = nullptr;
  node* last = nullptr;

  void push(int x);
  void pop();
  void print();
  void clear();
};

void Queue::push(int x) {
  if (!first) {
    first = new node(x, nullptr);
    last = first;
    return;
  }
  node* tmp = last;
  last = new node(x, nullptr);
  tmp->next = last;
}

void Queue::pop() {
  if (!first) {
    cout << "Pop: Cola vacía";
    return;
  }
  node* tmp = first;
  first = first->next;
  delete tmp;
}

void Queue::print() {
  cout << "First -> ";
  for (node* p = first; p; p = p->next) {
    cout << p->value << " -> ";
  }
  cout << "Last";
}

void Queue::clear() {
  while (first) {
    pop();
  }
}

int main() {
  Queue queue;
  queue.push(5);
  queue.push(15);
  queue.push(25);
  queue.push(35);
  queue.clear();
  queue.push(50);
  queue.print();
}