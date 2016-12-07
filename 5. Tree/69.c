/*********************************************
*
*  Check if elements of 2 BST are same or not
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

node *create2() {
  node *p = newNode(4);
  p->left = newNode(3);
  p->right = newNode(5);
  p->left->left = newNode(2);
  p->left->left->left = newNode(1);
  p->right->right = newNode(6);
  p->right->right->right = newNode(7);
  return p;
}

bool checkTree(node* r1, node* r2) {
    if(r1 == NULL && r2 == NULL)
      return true;
    else if((r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL))
        return false;
    else if(r1->data == r2->data)
      return checkTree(r1->left, r2->left) && checkTree(r1->right, r2->right);
    return false;
}

void inorder(node *root) {
  if(root) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void main() {
  node *root1;
  root1 = create();

  node *root2;
  root2 = create2();

  printf("\nInorder 1 -> ");
  inorder(root1);

  printf("\nInorder 2 -> ");
  inorder(root2);

  if(checkTree(root1, root2)) {
    printf("\nTree same");
  } else {
    printf("\nTrees not same");
  }
}
