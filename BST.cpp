#include <iostream>
#include <stack>
#include <queue>
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
  
  void inOrder(node* p);
  void preOrder(node* p);
  void postOrder(node* p);

  void ios(node* p);
  void levelPrint(node* p);
};

void BST::insert(int x) {
  node** p;
  if (find(x, p)) return;
  *p = new node(x);
}

void BST::remove(int x) {
  // TODO
}

bool BST::find(int x, node**& p) {
  p = &root;
  while (*p && (*p)->value != x) {
    p = &((*p)->nodes[x > (*p)->value]);
  }
  return *p != 0;
}

void BST::ios(node* p) {  // In-Order stack
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

void BST::inOrder(node* p) {
  if (!p) return;
  inOrder(p->nodes[0]);
  cout << p->value << " ";
  inOrder(p->nodes[1]);
}

void BST::preOrder(node* p) {
  if (!p) return;
  cout << p->value << " ";
  preOrder(p->nodes[0]);
  preOrder(p->nodes[1]);
}

void BST::postOrder(node* p) {
  if (!p) return;
  postOrder(p->nodes[0]);
  postOrder(p->nodes[1]);
  cout << p->value << " ";
}

void BST::levelPrint(node* p) {
  queue<node*> q;
  q.push(p);
  while(!q.empty()) {
    int lastPopped = p->value;
    p = q.front();
    if (p->value < lastPopped) cout << endl;
    cout << p->value << " ";
    if (p->nodes[0]) q.push(p->nodes[0]);
    if (p->nodes[1]) q.push(p->nodes[1]);
    q.pop();
  }
}

int main() {
  BST t;

                                            t.insert(10);
                    t.insert(4);                                    t.insert(15);
        t.insert(2);            t.insert(7);            t.insert(12);           t.insert(18);
  t.insert(1);t.insert(3);t.insert(5);t.insert(8);t.insert(11);t.insert(14);t.insert(17);t.insert(20);

  t.levelPrint(t.root);
}