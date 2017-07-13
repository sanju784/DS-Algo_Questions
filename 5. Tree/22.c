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

int sumAll(node *p) {
  if(!p) {
    return 0;
  }
  return p->data + sumAll(p->left) + sumAll(p->right);
}

void main () {
  node *root;
  root = create();
  printf("\n\nTotal sum of tree is %d", sumAll(root));
}
