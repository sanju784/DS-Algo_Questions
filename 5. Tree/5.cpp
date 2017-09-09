/*********************************************
*
*  Insert an element in binary tree
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

// using level order traversal
// inserting at fist null position
void insertInTree(node **p, int n) {
  node *newNode = (node*)malloc(sizeof(node));
  newNode->data = n;
  newNode->left = NULL;
  newNode->right = NULL;
	  
  if(*p == NULL) {
    *p = newNode;
	return;
  }
  queue <node*> q;
  q.push(*p);
  node *temp;
  while(!q.empty()) {
    temp = q.front();
    q.pop();
    if(temp->left == NULL) {
      temp->left = newNode;
      return;
    } else if(temp->right == NULL) {
      temp->right = newNode;
      return;
    } else {
      q.push(temp->left);
      q.push(temp->right);
    }
  }
}

void inOrder(node *p) {
  if(p) {
    inOrder(p->left);
    cout<<p->data<< " ";
    inOrder(p->right);
  }
}

int main() {
  node* root;
  root = create();
  int n;
  cout<<"\nInorder traversal of tree before insertion.\n";
  inOrder(root);
  cout<<"\nEnter the number you want to insert. ";
  cin>>n;
  
    insertInTree(&root, n);

  cout<<"\nInorder traversal of tree after insertion.\n";
  inOrder(root);
  return 0;
}
