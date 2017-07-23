/*********************************************
*
*  Find inoreder Successor in BST
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree{
  int data;
  struct tree *left;
  struct tree *right;
} node;

node *newNode(int val) {
  node *newN = (node*)malloc(sizeof(node));
  newN->data = val;
  newN->left = NULL;
  newN->right = NULL;
  return newN;
}
 
node *create() {
  node *p = newNode(4);
  p->left = newNode(2);
  p->right = newNode(6);
  p->left->left = newNode(1);
  p->left->right = newNode(3);
  p->right->left = newNode(5);
  p->right->right = newNode(7);
  return p;
}

node* getMin(node *root) {
  if(root == NULL)
    return NULL;
  while(root->left != NULL) {
      root = root->left;
  }
  return root;
}

node *inorderSuccessor(node *root, node *n){
  if(n->right)
    return getMin(n->right);
  node *succ = NULL;
  while(root != NULL) {
    if(n->data < root->data) {
      succ = root;
      root = root->left;
    } else if(n->data > root->data)
        root = root->right;
      else
        break;
  }
  return succ;
}

void main() {
  node *root = create();
  node *res = inorderSuccessor(root, root->left->left);
  printf("\nInorder Successor of %d is %d", root->left->left->data, res->data);
}