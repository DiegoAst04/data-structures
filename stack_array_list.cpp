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
class Stack {
  node<T>* top = nullptr;
  int* last = nullptr;
public:
  void push(T x);
  void pop();
  void print();

  ~Stack();
};

template <class T>
void Stack<T>::push(T x) {
  if (!top || last == top->A+4) { 
    top = new node<T>(top);
    last = top->A;
    *last = x;
    return;
  }
  last++;
  *last = x;
}

template <class T>
void Stack<T>::pop() {
  if (!top) {
    return;
  }
  last--;
  if (last == top->A-1) {
    node<T>* tmp = top;
    top = top->next;
    last = top->A+4;
    delete tmp;
    if (!top)
      last = nullptr;
  }
}

template <class T>
void Stack<T>::print() {
  for (node<T>* p = top; p; p=p->next) {
    cout << "[";
    for (int* i = p->A; i != last+1 && i <= p->A+4; i++) {
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

template <class T>
Stack<T>::~Stack() {
  while (top) {
    pop();
  }
}

int main() {
  Stack<int> s;
  
  for (int i = 0; i < 11; i++){
    s.push(i);
  }
  
  // s.pop();
  // s.pop();

  s.print();
}