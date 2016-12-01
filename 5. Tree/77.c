/*********************************************
*
*  Generate AVL tree of height h with minimum nodes
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
 
typedef struct tree{
  int data;
  struct tree *left;
  struct tree *right;
  int height;
} node;

node *createAVL(int h) {
	if (h <= 0)
		return NULL;
	static int count = 0;
	node *root = (node*)malloc(sizeof(node));
	root->left = createAVL(h-1);
	root->data = count++;
	root->right = createAVL(h-2);
	root->height = h;
	return root;
}

void inorder(node *root) {
	if(root) {
	  inorder(root->left);
	  printf("%d", root->data);
	  inorder(root->right);
    }
}

void main() {
	printf("\nEnter desired height ");
	int h;
	scanf("%d", &h);
	node *root = createAVL(h);
	inorder(root);
}