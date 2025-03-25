#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

// * Punteros
/* void bubbleSort(int* a, int size) {
  bool swapped;
  for (int i = 0; i < size; i++) {
    swapped = false;
    for (int* p = a; p < a + size - i; p++) {
      int* q = p+1;
      if (q < a+size && *p > *q) {
        swap(*p,*q);
        swapped = true;
      }
    }
    if (!swapped) break;
  }
}
*/

// * índices
void bubbleSort(int arr[], int size) {
  bool swapped;
  for (int i = 0; i < size; i++) {
    swapped = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(arr[j],arr[j+1]);
        swapped = true;
      }
    }
    if (!swapped) break;
  }
}

struct ListToSort {
  int A[500];

  virtual bool compare(int a, int b);
};

struct Less : ListToSort {
  bool compare(int a, int b) {
    return a < b;
  }
};

struct Greater : ListToSort {
  bool compare(int a, int b) {
    return a > b;
  }
};

void sort(int* a, long size, ListToSort* p) {
  // TODO
}

// TODO: functores, tomar tiempos

void fillArray(int* a, int size) {
  for (int* i = a; i < a+size; i++) {
    *i = rand() % (size+1);
  }
}

void printArray(int arr[], int size) {
  cout << "print: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  srand(time(0));

  const int size = 500;
  int A[size];
  fillArray(A, size);

  auto start = chrono::high_resolution_clock::now();
  bubbleSort(A,size);
  auto end = chrono::high_resolution_clock::now();

  chrono::duration<long double> duration = end - start;
  cout << "Tiempo: " << duration.count() << " segundos" << endl;
}