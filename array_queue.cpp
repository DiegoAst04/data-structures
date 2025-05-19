#include <iostream>
using namespace std;

template <class T>
struct Queue {
  T A[10];
  T* first = nullptr;
  T* last = nullptr;

  T push(T x);
  void pop();
  void print();
};

template <class T>
T Queue<T>::push(T x) {
  if (!first) {
    first = A;
    last = A;
    *last = x;
    return *last;
  }
  if (first != A && last == A+9) {
    last = A;
    *last = x;
    return *last;
  }
  if (last+1 == first || (first == A && last == A+9)) {
    cout << "Cola llena" << endl;
    return 0;
  }
  last++;
  *last = x;
  return *last;
}

template <class T>
void Queue<T>::pop() {
  if (first == last) {
    first = nullptr;
    last = nullptr;
    cout << "Cola Vacia" << endl;
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


int main() {
  Queue<int> queue;

  for (int i = 1; i < 6; i++) {
    queue.push(i);
  }
  
  queue.pop();
  queue.pop();
  queue.pop();
  
  queue.print();
}