#include <iostream>
using namespace std;

template <class T>
struct Stack {
  T A[10];
  T* top = nullptr;

  T push(T x);
  T pop();
  void print();

};

template <class T>
T Stack<T>::push(T x) {
  if (!top) {
    top = A;
    *top = x;
    return *top;
  }
  if (top == A+9) {
    cout << "Pila llena" << endl;
    return 0;
  }
  top++;
  *top = x;
  return *top;
}

template <class T>
T Stack<T>::pop() {
  if (!top) {
    cout << "Pila vacia" << endl;
    return 0;
  }
  if (top == A) {
    top = nullptr;
    return *A;
  }
  top--;
  return *(top+1);
}

template <class T>
void Stack<T>::print() {
  cout << "[";
  for (int* i = A; i && i <= top; i++) {
    cout << *i;
    if (i != top) cout << ", ";
  }
  cout << "] <- TOP" << endl;
}

int main() {
  Stack<int> stack;

  stack.push(6);
  stack.push(7);
  stack.push(10);

  stack.pop();
  
  stack.print();  
}