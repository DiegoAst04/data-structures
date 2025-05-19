#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct node {
  node* nodes[2] = { nullptr };
  int value;
  
  node(int x) {
    value = x;
  }
};

class BST {
public:
  node* root = nullptr;

  bool find(int x, node**& p);
  void insert(int x);
  void remove(int x);
  
  void InOrder(node* p);
  void PreOrder(node* p);
  void PostOrder(node* p);

  void ios(node* p);
  void drawChart();
};

void BST::insert(int x) {
  node** p;
  if (find(x, p)) return;
  *p = new node(x);
}

void BST::remove(int x) {
  
}

bool BST::find(int x, node**& p) {
  p = &root;
  while (*p && (*p)->value != x) {
    p = &((*p)->nodes[x > (*p)->value]);
  }
  return *p != 0;
}

void BST::ios(node* p) {
  stack<pair<node*, int>> S;
  S.emplace(p, 0);
  while (!S.empty()) {
    auto x = S.top();
    switch (x.second) {
    case 0:
      if (p->nodes[0]) p = p->nodes[0];
      else {
        S.top().second++;
        break;
      }
      S.top().second++;
      S.emplace(p,0);
      break;
    case 1:
      cout << x.first->value << " ";
      S.top().second++;
      break;
    case 2:
      if (p->nodes[1]) p = p->nodes[1];
      else {
        S.top().second++;
        break;
      }
      S.top().second++;
      S.emplace(p,0);
      break;
    case 3:
      S.pop();
      p = !S.empty() ? S.top().first : nullptr;
      break;
    }
  }
}

void BST::InOrder(node* p) {
  if (!p) return;
  InOrder(p->nodes[0]);
  cout << p->value << " ";
  InOrder(p->nodes[1]);
}

void BST::PreOrder(node* p) {
  if (!p) return;
  cout << p->value << " ";
  PreOrder(p->nodes[0]);
  PreOrder(p->nodes[1]);
}

void BST::PostOrder(node* p) {
  if (!p) return;
  PostOrder(p->nodes[0]);
  PostOrder(p->nodes[1]);
  cout << p->value << " ";
}

void BST::drawChart() {
  vector<int> A;

  cout << " "; PostOrder(root);

}

int main() {
  BST t;

                    t.insert(10);
              t.insert(4); t.insert(15);
  t.insert(2); t.insert(7);t.insert(12); t.insert(18);

  t.ios(t.root);
}