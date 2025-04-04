#include <iostream>
using namespace std;

struct Queue {
  int A[10];
  int* first = nullptr;
  int* last = nullptr;

  void push(int x);
  void pop();
  void print();

  ~Queue();
};

void Queue::push(int x) {
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

void Queue::pop() {
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

void Queue::print() {
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

Queue::~Queue() {
  while(!first) {
    pop();
  }
}

int main() {
  Queue queue;

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