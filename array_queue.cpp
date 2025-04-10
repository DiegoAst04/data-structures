#include <iostream>
using namespace std;

template <class T>
struct Queue {
  int A[10];
  T* first = nullptr;
  T* last = nullptr;

  void push(T x);
  void pop();
  void print();
  
  ~Queue();
};

template <class T>
void Queue<T>::push(T x) {
  if (!first) {
    first = A;
    last = A;
    *last = x;
    return;
  }
  if (first != A && last == A+9) {
    last = A;
    *last = x;
    return;
  }
  if (last+1 == first || (first == A && last == A+9)) {
    cout << "Cola llena" << endl;
    return;
  }
  last++;
  *last = x;
}

template <class T>
void Queue<T>::pop() {
  if (first == last) {
    first = nullptr;
    last = nullptr;
    cout << "Cola Vacía" << endl;
    return;
  }
  if (first == A+10) {
    first = A;
  }
  first++;
}

template <class T>
void Queue<T>::print() {
  cout << "first -> [";
  for (int* i = first; i && i != last+1; i++) {
    if (i == A+10) i = A;
    cout << *i;
    if (i != last) {
      cout << ", ";
    }
  }
  cout << "] <- last" << endl;
}

template <class T>
Queue<T>::~Queue() {
  while(!first) {
    pop();
  }
}

int main() {
  Queue<int> queue;

  for (int i = 1; i < 6; i++) {
    queue.push(i);
  }
  
  queue.pop();
  queue.pop();
  queue.pop();
  queue.pop();

  for (int i = 14; i < 22; i++) {
    queue.push(i);
  }

  for (int i = 0; i < 10; i++) {
    queue.pop();
  }
  
  queue.print();
}