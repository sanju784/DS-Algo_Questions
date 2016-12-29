/*********************************************
*
*  Find Floor and Ceil of a number in a BST
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
  int data;
  struct tree *left;
  struct tree *right;
} node;

node *newNode(int val) {
  node *newN = (node*)malloc(sizeof(node));
  newN->data = val*3;
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

node* Floor(node *root, int k) {
  if(!root)
    return NULL;
  if(root->data > k)
    return Floor(root->left, k);
  node *temp = Floor(root->right, k);
  if(!temp)
    return root;
  return temp;
}

node* Ceil(node *root, int k) {
  if(!root)
    return NULL;
  if(root->data < k)
    return Ceil(root->right, k);
  node *temp = Ceil(root->left, k);
  if(!temp)
    return root;
  return temp;
}

void main() {
  node *root;
  root = create();
  int k;
  printf("\nEnter k : ");
  scanf("%d", &k);
  node *res = Floor(root, k);
  if(res)
    printf("\nFloor value of %d is %d", k, res->data);
  res = Ceil(root, k);
  if(res)
    printf("\nCeil value of %d is %d\n", k, res->data);
}
