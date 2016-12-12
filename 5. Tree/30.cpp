/*********************************************
*
*  Spiral traversal of a tree
*
*/////////////////////////////////////////////

#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

typedef struct tree {
  int data;
  struct tree *left;
  struct tree *right;
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

void inorder(node *root) {
    if(root) {
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
    }
}

void spiralTraversal(node *root) {
  if(root == NULL)
    return;
  stack<node*> s1;
  stack<node*> s2;
  s1.push(root);
  while(!s1.empty() || !s2.empty()) {
    while(!s1.empty()) {
        node *temp = s1.top();
        s1.pop();
        cout<<temp->data<<" ";
        if(temp->right)
            s2.push(temp->right);
        if(temp->left)
            s2.push(temp->left);
    }

    while(!s2.empty()) {
        node *temp = s2.top();
        s2.pop();
        cout<<temp->data<<" ";
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }
  }
}


int main() {
  node *root;
  root = create();
  cout<<"\nInorder traversal of tree is ";
  inorder(root);
  cout<<"\nSpiral traversal of tree is ";
  spiralTraversal(root);
  return 0;
}
