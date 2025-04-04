#include <iostream>
using namespace std;

template <class T>
struct Stack {
  T A[10];
  T* head = nullptr;
  T* top = nullptr;

  void push(T x);
  void pop();
  void print();

  ~Stack();
};

template <class T>
void Stack<T>::push(T x) {
  if (!head) {
    head = A;
    top = A;
    *top = x;
    return;
  }
  if (top == A+9) {
   cout << "Pila llena" << endl;
   return;
  }
  top++;
  *top = x;
}

template <class T>
void Stack<T>::pop() {
  if (!top) {
    cout << "Pila vacia" << endl;
  }
  if (top == head) {
    top = nullptr;
    head = nullptr;
    return;
  }
  top--;
}

template <class T>
void Stack<T>::print() {
  cout << "HEAD -> [";
  for (int* i = head; i && i <= top; i++) {
    cout << *i;
    if (i != top) cout << ", ";
  }
  cout << "] <- TOP" << endl;
}

template <class T>
Stack<T>::~Stack() {
  while (top) {
    pop();
  }
  cout << "Wea destruida exitosamente" << endl;
}

int main() {
  Stack<int> stack;

  for (int i = 0; i < 10; i++) {
    stack.push(i);
  }
  stack.print();
}