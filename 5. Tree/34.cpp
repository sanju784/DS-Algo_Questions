/*********************************************
*
*  fill next sibling pointer of a tree - Iteration
*
*/////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

typedef struct tree {
  int data;
  struct tree *left;
  struct tree *right;
  struct tree *nextSibling;
} node;

node *create() {
  node* p;
  int n;
  cout<<"\nEnter data (Enter -1 if no child node) : ";
  cin>>n;
  if(n == -1) {
    return NULL;
  }
  p = (node*)malloc(sizeof(node));
  p->data = n;
  cout<<"\nEnter left child of "<<n;
  p->left = create();
  cout<<"\nEnter right child of "<<n;
  p->right = create();
  return p;
}

void fillNextSibling(node *p) {
  if(!p) return;
  queue<node*> q;
  q.push(p);
  q.push(NULL);
  node *temp;
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    if(temp == NULL && !q.empty()) {
        q.push(NULL);
    } else if (temp != NULL) {
      temp->nextSibling = q.front();
      if(temp->left)
        q.push(temp->left);
      if(temp->right)
        q.push(temp->right);
    }
  }
}

void inOrder(node *p) {
  if(p) {
    inOrder(p->left);
    cout<<p->data<<" ";
    inOrder(p->right);
  }
}

int main() {
  node *root;
  root = create();
  cout<<"\nInorder traversal of tree is ";
  inOrder(root);
  fillNextSibling(root);
  return 0;
}
