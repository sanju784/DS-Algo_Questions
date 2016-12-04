/*********************************************
*
*  Print all elements of a BST in the range n1 and n2
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
  p->data = n*3;
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

void printRange(node *root, int n1, int n2) {
  if(root == NULL)
    return;
  if(n1 <= root->data)
     printRange(root->left, n1, n2);
  if(n1 <= root->data && n2 >= root->data)  
    printf("%d ", root->data);
  if(n2 >= root->data)
    printRange(root->right, n1, n2);
}

void main() {
  node *root = createBST();
  int n1, n2;
  printf("\nEnter range : ");
  scanf("%d %d", &n1, &n2);
  printRange(root, n1, n2);
}