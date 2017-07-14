#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
  int data;
  struct treeNode *left;
  struct treeNode *right;
} node;

node *create() {
  int n;
  node *p;
  printf("\nEnter data (Enter -1 if no child node)\n");
  scanf("%d", &n);
  if (n == -1) return NULL;
  p = (node*) malloc(sizeof(node));
  p->data = n;
  printf("\nEnter left child of %d ", n);
  p->left = create();
  printf("\nEnter right child of %d ", n);
  p->right = create();
  return p;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int maxDiameter(node *root, int * height) {
  int lh = 0, rh = 0;
  int ldiameter = 0, rdiameter = 0;
  if(root == NULL) {
    *height = 0;
    return 0;
  }

  ldiameter = maxDiameter(root->left, &lh);
  rdiameter = maxDiameter(root->right, &rh);

  *height = max(lh, rh) + 1;

  return max(lh + rh + 1, max(ldiameter, rdiameter));
}

void main () {
  node *root;
  root = create();
  int height = 0;
  printf("\n\nMaximum Diameter of tree is %d", maxDiameter(root, &height));
}