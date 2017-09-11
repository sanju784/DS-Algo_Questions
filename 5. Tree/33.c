/*********************************************
*
*  Draw tree from preorder traversal
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
  int data;
  struct treeNode *left;
  struct treeNode *right;
} node;

void inorder(node *root) {
    if(root) {
      inorder(root->left);
      printf("%d ", root->data);
      inorder(root->right);
    }
}

node* newNode (int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *createTree(int pre[], char preN[], int *index, int n) {
  //value of current index need to be saved
  int i = *index;
  if(i == n)
    return NULL;
  node *temp = newNode(pre[i]);
  //the index was saved before as here we are changing the index value, but at next line we need previous value
  (*index)++;
  if(preN[i] == 'N')
  {
      temp->left = createTree(pre, preN, index, n);
      temp->right = createTree(pre, preN, index, n);
  }
  return temp;
}

void main () {
  node *root = NULL;
  int pre[] = {10, 30, 20, 5, 15};
  char preN[] = {'N', 'N', 'L', 'L', 'L'};
  int n = sizeof(pre)/sizeof(pre[1]);
  int index = 0;
  root = createTree(pre, preN, &index, n);
  printf("\nThe inorder traversal of tree is :");
  inorder(root);
}
