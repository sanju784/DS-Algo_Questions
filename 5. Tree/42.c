/*********************************************
*
*  Check that trees are isomorphic to each other
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

bool isIsomorphic(node *root1, node *root2) {
  if(root1 == NULL && root2 == NULL)
    return true;
  if((root1 && !root2) || (!root1 && root2))
    return false;
  return isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
}


void main () {
  node *root1, *root2;
  printf("\nCreate tree 1");
  root1 = create();
  printf("\nCreate tree 2");
  root2 = create();
  if(isIsomorphic(root1, root2)) {
    printf("\nBoth trees are Isomorphic");
  } else {
    printf("\nTrees are not Isomorphic");
  }

}