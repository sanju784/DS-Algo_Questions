/*********************************************
*
*  Check if given BST is AVL
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

int max(int a, int b) {
  return (a >= b) ? a : b;
}

int height (node *root) {
  if(root == NULL)
    return 0;
  return 1 + max(height(root->left), height(root->right));
}

bool isAVL(node *root) {
  int lh, rh;
  if(root == NULL)
    return true;
  lh = height(root->left);
  rh = height(root->right);

  if(abs(lh-rh) <= 1 && isAVL(root->left) && isAVL(root->right))
    return true;

  return false;
}

void main() {
  node *root = create();
  if(isAVL(root))
    printf("\nTree is balanced");
  else
    printf("\nTree is not balanced");
}