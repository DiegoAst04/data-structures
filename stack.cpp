#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct node {
  int value;
  node<T>* next;

  node(int value, node<T>* next) {
    this->value = value;
    this->next = next;
  }
};

template <class T>
struct Stack {
  node<T>* top = nullptr;

  void push(T x);
  void pop();
  void print();
  int peek();
  bool isEmpty();
  void clear();
  vector<T> toVector();

  ~Stack();
};

template <class T>
void Stack<T>::push(T x) {
  top = new node<T>(x, top);
}

template <class T>
void Stack<T>::print() {
  if (!top) {
    cout << "print:\tPila vacia" << endl;
    return;
  }
  for (node<T>* p = top ; p; p = p->next) {
    cout << (*p).value;
    if (p->next) {
      cout << " -> ";
    }
  }
  cout << endl;
}

template <class T>
void Stack<T>::pop() {
   if (top) {
    node<T>* tmp = top;
    top = top->next;
    delete tmp;
  } else {
    cout << "pop:\tPila vacia" << endl;
  }
}

template <class T>
int Stack<T>::peek() {
  if (!top) {
    return -1;
  }
  return (*top).value;
}

template <class T>
bool Stack<T>::isEmpty() {
  if (top) {
    return 0;
  }
  return 1;
}

template <class T>
void Stack<T>::clear() {
  while (top) {
    pop();
  }
  cout << "clear:\tpila limpia" << endl;
}

template <class T>
vector<T> Stack<T>::toVector() {
  vector<T> A;
  for (node<T>* p = top; p; p = p->next) {
    A.push_back((*p).value);
  }
  return A;
}

template <class T>
Stack<T>::~Stack() {
  clear();
}

int main() {
  Stack<int> stack;
  stack.print();
  stack.pop();
  stack.clear();
  cout << "peek:\t" << stack.peek() << endl;
  cout << "is empty?:\t" << stack.isEmpty() << endl;
  stack.push(5);
  cout << "is empty?:\t" << stack.isEmpty() << endl;
  stack.push(10);
  cout << "peek:\t" << stack.peek() << endl;
  stack.push(14);
  stack.push(30);
  stack.pop();
  cout << "peek:\t" << stack.peek() << endl;
  stack.pop();
  stack.push(30);
  
  stack.print();
  
  stack.clear();
  stack.print();
  
  /* vector<int> B = stack.toVector();
  for (int i = 0; i < B.size(); i++) {
    cout << B[i] << ", ";
  } */
}