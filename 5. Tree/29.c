/*********************************************
*
*  Print all ancestors of a node
*
*/////////////////////////////////////////////

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

bool printAncestors(node *root, int val) {
    if(root == NULL)
        return false;
    if(root->data == val)
        return true;
    if(printAncestors(root->left, val) || printAncestors(root->right, val)) {
        printf(" %d", root->data);
        return true;
    }
    return false;
}

void main () {
  node *root;
  root = create();
  int n;
  printf("\nEnter value whose ancestors you need : ");
  scanf("%d", &n);
  if(printAncestors(root, n)) {
    printf(" are ancestors of %d.", n);
  } else {
    printf("%d has no ancestor.", n);
  }
}
