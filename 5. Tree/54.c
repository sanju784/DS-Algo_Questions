/*********************************************
*
*  Convert a BST into Circular DLL
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

node *concatenate(node *leftList, node *rightList) {
  if(leftList == NULL)
    return rightList;
  if(rightList == NULL)
    return leftList;

  node *leftLast = leftList->left;

  node *rightLast = rightList->left;

  leftLast->right = rightList;
  rightList->left = leftLast;

  leftList->left = rightLast;
  rightLast->right = leftList;

  return leftList;
}

node *treeToDLL(node *root) {
  if(root == NULL)
    return NULL;
  node *left = treeToDLL(root->left);
  node *right = treeToDLL(root->right);

  root->left = root->right = root;

  return concatenate(concatenate(left, root), right);
}

void displayList(node *head) {
  printf("\nThe circular DLL is ");
  node *itr = head;
  do {
    printf("%d ", itr->data);
    itr = itr->right;
  } while(head != itr);
}

void main() {
  node *root = createBST();
  node *head = treeToDLL(root);
  displayList(head);
}