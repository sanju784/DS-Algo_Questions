/*********************************************
*
*  Print all root to leaf path
*
*/////////////////////////////////////////////

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

void printPath(int data[], int n) {
  int i;
  printf("\nPath is : ", n);
  for (i = 0;i < n;i++)
    printf("%d ", data[i]);
}

void getAllPath(node *root, int path[], int pathLen) {
  if(root == NULL) return;

  path[pathLen] = root->data;
  pathLen++;
  if(root->left == NULL && root->right == NULL) 
    printPath(path, pathLen);
  else {
    getAllPath(root->left, path, pathLen);
    getAllPath(root->right, path, pathLen);
  }
}

void main () {
  node *root;
  root = create();
  int path[10];
  int length = 0;
  getAllPath(root, path, length);
}