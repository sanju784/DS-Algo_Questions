/*********************************************
*
*  Find k-th smallest element in BST
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

//This is using inorder traversal
node* kthSmallestElement(node *root, int k) {
  static int count = 0;
  if(!root)
    return NULL;
  if(root) {
    node *temp = kthSmallestElement(root->left, k);
    if(temp)
        return temp;
    if(++count == k)
        return root;
    return kthSmallestElement(root->right, k);
  }
}

void main() {
  node *root;
  root = create();
  int k;
  printf("\nEnter k : ");
  scanf("%d", &k);
  node *res = kthSmallestElement(root, k);
  if (res) {
    printf("\nThe %d element of tree is %d ", k, res->data);
  } else {
    printf("\nThe number is out of range.");
  }
}