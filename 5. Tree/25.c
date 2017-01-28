#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isMirror(node *p1, node *p2) {
  if (p1 == NULL && p2 == NULL) return 1;
  if (p1 == NULL || p2 == NULL) return 0;
  if(p1->data != p2->data) return 0;
  else return isMirror(p1->left, p2->right) && isMirror(p1->right, p2->left);
}

void main () {
  printf("\nCreate tree 1 :");
  node *root1;
  root1 = create();
  printf("\nCreate tree 2 :");
  node *root2;
  root2 = create();
  if(isMirror(root1, root2)) {
    printf("\nBoth trees are mirror of each other.");
  } else {
    printf("\nTrees are not mirror of each other.");
  }
}
