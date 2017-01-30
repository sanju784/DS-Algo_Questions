/*********************************************
*
*  Construct binary tree from inorder and preorder
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
  char data;
  struct treeNode *left;
  struct treeNode *right;
} node;

node *createNode(char val) {
  node *newNode = (node*)malloc(sizeof(node));
  newNode->data = val;
  newNode->left = newNode->right = NULL;
  return newNode;
}

int search(char arr[], int start, int end, char val) {
    int i;
    for(i = start; i < end; i++) {
        if(arr[i] == val)
            return i;
    }
}

node* buildTree(char in[], char pre[], int inStart, int inEnd) {
    static int preIndex = 0;
    if(inStart > inEnd)
        return NULL;
    node* newNode = createNode(pre[preIndex++]);
    if(inStart == inEnd)
        return newNode;
    int inIndex = search(in, inStart, inEnd, newNode->data);

    newNode->left = buildTree(in, pre, inStart, inIndex-1);
    newNode->right = buildTree(in, pre, inIndex+1, inEnd);

    return newNode;
}

void inOrder(node* root) {
  if(root) {
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
  }
}

void main () {
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in) / sizeof(in[0]);
  node *root = buildTree(in, pre, 0, len - 1);
  printf("Inorder traversal of created tree is -> ");
  inOrder(root);
}
