/*********************************************
*
*  Find Lowest Common Ancestor of 2 nodes
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

node* findLCA(node *root, int a, int b) {
  if(root == NULL) return NULL;
  if(root->data == a || root->data == b)
    return root;

  node* left_lca = findLCA(root->left, a, b);
  node* right_lca = findLCA(root->right, a, b);

  if(left_lca && right_lca)
    return root;

  return (left_lca != NULL) ? left_lca : right_lca;
}

void main () {
  node *root;
  root = create();
  int n1, n2;
  printf("\nEnter nodes whose LCA is needed .");
  scanf("%d %d", &n1,&n2);
  node *res = findLCA(root, n1, n2);
  printf("\nLCA(%d, %d) is %d", n1,n2,res->data);
}
