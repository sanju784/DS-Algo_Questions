/*********************************************
*
*  Generate Full Balanced BST of height h
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
 
typedef struct tree{
  int data;
  struct tree *left;
  struct tree *right;
} node;
 
node* fullBalancedTree(int h) {
	static int count = 0;

	if(h == 0)
		return NULL;
	node *root = (node*)malloc(sizeof(node));
	root->left = fullBalancedTree(h-1);
	root->data = count++;
	root->right = fullBalancedTree(h-1);
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
	printf("\nEnter tree height ");
	int h;
	scanf("%d", &h);
	node *root = fullBalancedTree(h);
	inorder(root);
}