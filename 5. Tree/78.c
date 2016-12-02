/*********************************************
*
*  Count numbers of nodes in the range (a,b) in BST
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

int countNodeRange(node *root, int a, int b) {
  if(root == NULL)
    return 0;
  else if(a > root->data)
    countNodeRange(root->right, a, b);
  else if(b < root->data)
    countNodeRange(root->left, a, b);
  else if(root->data >=a && root->data <= b)
    return countNodeRange(root->left, a, b) + countNodeRange(root->right, a, b) + 1;
}

void main() {
  node *root = create();
  printf("\nEnter range ");
  int a, b;
  scanf("%d %d", &a, &b);
  printf("\nTotal nodes in Range %d and %d is %d", a, b, countNodeRange(root, a, b));
}