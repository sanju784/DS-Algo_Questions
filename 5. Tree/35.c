/*********************************************
*
*  fill next sibling pointer of a tree - Iteration
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode{
  int data;
  struct treeNode *left;
  struct treeNode *right;
  struct treeNode *nextSibling;
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

void fillNextSibling(node *root) {
    if(!root) return;
    if(root->left)
        root->left->nextSibling = root->right;
    if(root->right)
        root->right->nextSibling = (root->nextSibling) ? root->nextSibling->left : NULL;
    fillNextSibling(root->left);
    fillNextSibling(root->right);
}

void inOrder(node *p) {
  if(p) {
    inOrder(p->left);
    printf("%d ", p->data);
    inOrder(p->right);
  }
}

//suitable only for complete binary tree
void levelTravesal(node *root) {
  printf("%d ", root->data);
  node *lchild = root->left;
  while(lchild) {
    printf("%d ", lchild->data);
    node *sibling = lchild->nextSibling;
    while(sibling) {
        printf("%d ", sibling->data);
        sibling = sibling->nextSibling;
    }
    lchild = lchild->left;
  }
}

void main () {
  node *root;
  root = create();
  fillNextSibling(root);
  printf("\nThe Level Order traversal of tree is ");
  levelTravesal(root);
}
