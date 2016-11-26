/*********************************************
*
*  Check that a given tree is BST
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

bool isBST(node *root, int *prev) {
  if(root) {
    if(!isBST(root->left, prev))
        return false;
    if(root->data < *prev)
        return false;
    *prev = root->data;
    return isBST(root->right, prev);
  }
  return true;
}

void main() {
  node *root;
  root = create();

  int prev = INT_MIN;

  if(isBST(root, &prev)) {
    printf("\nTree is BST.\n");
  } else {
    printf("\nTree is not BST.\n");
  }
}