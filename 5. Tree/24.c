/*********************************************
*
*  Convert a tree to its mirror tree
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

void makeMirror(node *p) {
    node *temp;
    if(p) {
        makeMirror(p->left);
        makeMirror(p->right);
        //swapping the left and right child from the end
        temp = p->left;
        p->left = p->right;
        p->right = temp;
    }
}

void inOrder(node *p) {
  if(p) {
    inOrder(p->left);
    printf("%d ", p->data);
    inOrder(p->right);
  }
}

void main () {
  node *root;
  root = create();
  printf("\nInOrder traversal of tree before mirroring : ");
  inOrder(root);
  makeMirror(root);
  printf("\nInOrder traversal of tree after mirroring : ");
  inOrder(root);
}
