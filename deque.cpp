#include <iostream>
using namespace std;

class Deque {
  int** map;
  int** front = nullptr;
  int** back = nullptr;
  int* first = nullptr;
  int* last = nullptr;

  int sizeA;
  int sizeB;

public:
  void pushFront(int x);
  void pushBack(int x);
  void popFront();
  void popBack();
  int operator[](int x);
  void print();

  Deque(int sizeA, int sizeB) {
    this->sizeA = sizeA;
    this->sizeB = sizeB;
    map = new int*[sizeA] {nullptr};
  }
};

void Deque::pushFront(int x) {
  if (!back) {
    back = map + (*map-*map+sizeA-1)/2;
    *back = new int[sizeB];
    front = back;
    first = *back + (*back-*back+sizeB-1)/2;
    last = first;
    *last = x;
    return;
  }
  if (first == *back) {
    back--;
    *back = new int[sizeB];
    first = *back+sizeB-1;
    *first = x;
    return;
  }
  first--;
  *first = x;
}

void Deque::pushBack(int x) {
  if (!front) {
    front = map + (*map-*map+sizeA-1)/2;
    *front = new int[sizeB];
    back = front;
    first = *front + (*front-*front+sizeB-1)/2;
    last = first;
    *last = x;
    return;
  }
  if (last == *front+sizeB-1) {
    front++;
    *front = new int[sizeB];
    last = *front;
    *last = x;
    return;
  }
  last++;
  *last = x;
}

void Deque::popFront() {
  if (!back) {
    cout << "popFront: Deque vacio";
    return;
  }
  if (last == *back + sizeB -1) {
    delete [] *back;
    back = nullptr;
    back++;
    return;
  }
  last++;
}

void Deque::popBack() {
  if (!front) {
    cout << "popBack: Deque vacio";
    return;
  }
  if (last == *front) {
    delete [] *front;
    *front = nullptr;
    front--;
    last = *front + sizeB - 1;
    return;
  }
  last--;
}

int Deque::operator[](int x) {
  int algo = x/sizeB;
  int algo2 = x%sizeB;
  return *(*(back+algo)+algo2-1);
}

void Deque::print() {
  cout << "[";
  for (int** p = back; p <= front; p++) {
    cout << "(";
    bool isFirstHere = first >= *p && first < *p+sizeB;
    for (int* q = isFirstHere ? first : *p; q != *p + sizeB && q != last + 1; q++) {
      cout << *q;
      if (q+1 < *p+sizeB && q != last) {
        cout << ", ";
      }
    }
    cout << ")";
    if (p!=front) cout << ", ";
  }
  cout << "]";
}

int main() {
  Deque d(7,5);

  d.pushFront(3);
  d.pushFront(4);
  d.pushFront(5);
  d.pushFront(6);

  d.pushBack(10);
  d.pushBack(13);
  d.pushBack(17);
  d.pushBack(19);

  d.print();

  cout << endl << d[7];
}