#include <iostream>
#include <vector>
using namespace std;

struct node {
  int value;
  node* next;

  node(int value, node* next) {
    this->value = value;
    this->next = next;
  }
};

struct Stack {
  node* head = nullptr;
  node* top = nullptr;

  void push(int x);
  void pop();
  void print();
  int peek();
  bool isEmpty();
  void clear();
  vector<int> toVector();

  ~Stack();
};

void Stack::push(int x) {
  if (!head) {
    head = new node(x, nullptr);
    top = head;
  } else {
    node* tmp = new node(x, top);
    top = tmp;
  }
}

void Stack::print() {
  if (!top) {
    cout << "print:\tPila vacia" << endl;
    return;
  }
  
  for (node* p = top ; p->next; p = p->next) {
    cout << (*p).value << " -> ";
  }
  cout << (*head).value << endl;
}

void Stack::pop() {
   if (top) {
    node* tmp = top;
    top = top->next;
    delete tmp;
  } else {
    cout << "pop:\tPila vacia" << endl;
  }
}

int Stack::peek() {
  if (!top) {
    return -1;
  }
  return (*top).value;
}

bool Stack::isEmpty() {
  if (top) {
    return 0;
  }
  return 1;
}

void Stack::clear() {
  while (top) {
    pop();
  }
  cout << "clear:\tpila limpia" << endl;
}

vector<int> Stack::toVector() {
  vector<int> A;
  for (node* p = top; p; p = p->next) {
    A.push_back((*p).value);
  }
  return A;
}

Stack::~Stack() {
  clear();
}

int main() {
  Stack stack;
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