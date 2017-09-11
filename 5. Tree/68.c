/*********************************************
*
*  Trim a tree so that all elements of it are in the range n1 and n2
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

node* trimTree(node *root, int n1, int n2) {
  if(root == NULL)
    return NULL;

  root->left = trimTree(root->left, n1, n2);
  root->right = trimTree(root->right, n1, n2);
  //replacing the current node with its right subtree if its value is less than range
  //it is so because right subtree will have the value greater than lower limit of range
  if(root->data < n1) {
    node *rChild = root->right;
    free(root);
    return rChild;
  }
  //replacing the current node with its left subtree if its value is greater than range
  //it is so because left subtree will have the value less than upper limit of range
  if(root->data > n2) {
    node *lChild = root->left;
    free(root);
    return lChild;
  }
  return root;
}

void inorder(node *root) {
  if(root) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void main() {
  node *root = createBST();
  int n1, n2;
  printf("\nEnter range : ");
  scanf("%d %d", &n1, &n2);
  printf("\nInorder before trim  ");
  inorder(root);
  root = trimTree(root, n1, n2);
  printf("\nInorder after trim  ");
  inorder(root);
}
