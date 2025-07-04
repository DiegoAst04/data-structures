#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct node {
  node* nodes[2] = { nullptr };
  int value;
  int height;
  int balFac;
  
  node(int x) {
    value = x;
    height = 1;
    balFac = 0;
  }
};

class AVL {
  int height(node* p) {
      return p ? p->height : 0;
  }
  int bal(node* p) {
      return p ? p->balFac : 0;
  }
  void update(node* p) {
      if (!p) return;
      int hl = height(p->nodes[0]);
      int hr = height(p->nodes[1]);
      p->height = max(hl, hr) + 1;
      p->balFac = hr - hl;
  }
  void balance(node** p) {
    update(*p);
    int bf = (*p)->balFac;
    if (bf > 1) {
      if (bal((*p)->nodes[1]) < 0) {
        rightRotation(&((*p)->nodes[1]));
      }
      leftRotation(p);
    }
    else if (bf < -1) {
      if (bal((*p)->nodes[0]) > 0) {
        leftRotation(&((*p)->nodes[0]));
      }
      rightRotation(p);
    }
  }
  void leftRotation(node** p) {
    node* oldRoot = *p;
    node* newRoot = oldRoot->nodes[1];
    if (!newRoot) return;
    oldRoot->nodes[1] = newRoot->nodes[0];
    newRoot->nodes[0] = oldRoot;
    update(oldRoot);
    update(newRoot);
    *p = newRoot;
  }

  void rightRotation(node** p) {
    node* old = *p;
    node* nw = old->nodes[0];
    if (!nw) return;
    old->nodes[0] = nw->nodes[1];
    nw->nodes[1] = old;
    update(old);
    update(nw);
    *p = nw;
  }
  
public:
  node* root = nullptr;

  bool find(int x, node**& p, stack<node**>& sp);
  void insert(int x);
  void remove(int x);

  void levelPrint(node* p);
};

bool AVL::find(int x, node**& p, stack<node**>& sp) {
  p = &root;
  while (*p && (*p)->value != x) {
    sp.push(p);
    p = &((*p)->nodes[x > (*p)->value]);
  }
  return *p != 0;
}

void AVL::insert(int x) {
  node** p;
  std::stack<node**> sp;
  if (find(x, p, sp)) return;
  *p = new node(x);
  while (!sp.empty()) {
    node** c = sp.top();
    sp.pop();
    balance(c);
  }
}

void AVL::remove(int x) {
  node** p;
  std::stack<node**> sp;
  if (!find(x, p, sp)) return;
  node* q = *p;
  if (q->nodes[0] && q->nodes[1]) {
    node** n = &(q->nodes[1]);
    sp.push(p);
    while ((*n)->nodes[0]) {
      sp.push(n);
      n = &((*n)->nodes[0]);
    }
    q->value = (*n)->value;
    p = n;
  }

  node* child = (*p)->nodes[0] ? (*p)->nodes[0] : (*p)->nodes[1];
  delete* p;
  *p = child;

  while (!sp.empty()) {
    node** c = sp.top();
    sp.pop();
    balance(c);
  }
}

void AVL::levelPrint(node* p) {
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
  AVL t;

  t.insert(1);
  t.insert(8);
  t.insert(3);
  t.insert(7);
  t.insert(2);
  t.insert(9);
  t.insert(4);
  t.insert(5);
  t.insert(6);
  t.insert(21);
  t.insert(25);
  t.insert(36);

  t.remove(7);

  t.levelPrint(t.root);
}