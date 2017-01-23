/*********************************************
*
*  Check for path with given sum
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
  printf("Path is : ", n);
  for (i = 0;i < n;i++)
    printf("%d ", data[i]);
}

void getsumPath(node *root, int path[], int pathLen, int sum) {
  if(root == NULL) return;
  path[pathLen] = root->data;
  pathLen++;
  sum = sum - root->data;
  if(root->left == NULL && root->right == NULL && sum == 0) 
    printPath(path, pathLen);
  else {
    getsumPath(root->left, path, pathLen, sum);
    getsumPath(root->right, path, pathLen, sum);
  }
}

void main () {
  node *root;
  root = create();
  int path[10];
  int length = 0;
  int n;
  printf("\nEnter sum: ");
  scanf("%d", &n);
  getsumPath(root, path, length, n);
}