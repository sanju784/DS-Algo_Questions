/*********************************************
*
*  Find Lowest Common Ancestor of 2 nodes in a BST
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
  int data;
  struct treeNode *left;
  struct treeNode *right;
} node;

node *newNode(int n) {
  node *p = (node*)malloc(sizeof(node));
  p->data = n;
  p->left = NULL;
  p->right = NULL;
  return p;
}

/**
     4
    / \
  2     6
 / \   / \
1   3 5   7

*/
node *createBST() {
  node *p = newNode(4);
  p->left = newNode(2);
  p->right = newNode(6);
  p->left->left = newNode(1);
  p->left->right = newNode(3);
  p->right->left = newNode(5);
  p->right->right = newNode(7);
  return p;
}

node* findLCA(node* root, int a, int b) {
  while(root != NULL) {
    if(a <= root->data && b >= root->data) {
      return root;
    } else if (root->data > a && root->data > b) {
      root = root->left;
    } else {
      root = root->right;
    }
  }
}

void main() {
  node *root = createBST();
  int n1, n2;
  printf("\nEnter numbers whose Lowest Common Ancestor is needed ");
  scanf("%d %d", &n1, &n2);
  if(n1 > n2){
    int n = n1;
    n1 = n2;
    n2 = n;
  }
  node *res = findLCA(root, n1, n2);
  if (res) {
    printf("\nThe LCA of %d and %d is %d", n1, n2, res->data);
  } else {
    printf("\nNo LCA found");
  }
}