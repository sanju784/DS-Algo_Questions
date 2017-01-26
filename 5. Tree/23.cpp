/*********************************************
*
*  sum of all elements in binary tree - iteration
*
*/////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

typedef struct tree {
  int data;
  struct tree *left, *right;
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

int sumAll(node *p) {
  if(!p) return 0;
  queue<node*> q;
  node * temp;
  int sum = 0;
  q.push(p);
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    sum = sum + temp->data;
    if(temp->left)
        q.push(temp->left);
    if(temp->right)
        q.push(temp->right);
  }
  return sum;
}

int main() {
  node *root;
  root = create();
  cout<<"\nThe sum of all tree node is "<<sumAll(root);
  return 0;
}
