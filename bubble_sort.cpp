#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

// * Punteros
/* void bubbleSort(int* a, int size) {
  for (int i = 0; i < size; i++) {
    for (int* p = a; p < a + size - i - 1; p++) {
      if (*p > *(p+1))
        swap(*p,*(p+1));
    }
  }
} */

// * índices
void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j+1])
        swap(arr[j],arr[j+1]);
    }
  }
}

// * Polimorfismo
/* struct Comparator {
  virtual bool compare(int a, int b) = 0;
};

struct Less : Comparator {
  bool compare(int a, int b) {
    return a < b;
  }
};

struct Greater : Comparator {
  bool compare(int a, int b) {
    return a > b;
  }
};

void sort(int* a, int size, Comparator* p) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i-1; j++) {
      if (p->compare(a[j],a[j+1]))
        swap(a[j],a[j+1]);
    }
  }
} */

// * Functores
struct Less {
  bool compare(int a, int b) {
    return a < b;
  }
};

struct Greater {
  bool compare(int a, int b) {
    return a > b;
  }
};

// TODO: 
template <class T>
void sort(int* a, int size, T fo) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i-1; j++) {
      if (fo.compare(a[j],a[j+1]))
        swap(a[j],a[j+1]);
    }
  }
}

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
  
  Greater g;
  const int size = 1000;
  int A[size];
  fillArray(A, size);

  void (*functionPtr)(int*, int) = bubbleSort;
  
  auto start = chrono::high_resolution_clock::now();
  //bubbleSort(A,size);     // indices y punteros
  //sort(A,size,&g);        // polimorfismo
  functionPtr(A,size);    // puntero a funcion (indices)
  //sort(A,size, g);        // functor
  auto end = chrono::high_resolution_clock::now();

  //printArray(A,size);

  chrono::duration<long double> duration = end - start;
  cout << "Tiempo: " << duration.count() << " segundos" << endl;
}