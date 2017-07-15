/*********************************************
*
*  Sum of all elements in N-array tree
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	int data;
	struct treeNode *firstChild;
	struct treeNode *nextSibling;
} node;

node *newNode(int val) {
	node *newN = (node*)malloc(sizeof(node));
	newN->data = val;
	newN->firstChild = NULL;
	newN->nextSibling = NULL;
}

int sumAll(node *root) {
	if(root == NULL) return 0;
	return root->data + sumAll(root->firstChild) + sumAll(root->nextSibling);
}

void main () {
	node* root;
	root = newNode(1);
	root->firstChild = newNode(2);
	root->firstChild->nextSibling = newNode(3);
	root->firstChild->nextSibling->nextSibling = newNode(4);
	root->firstChild->firstChild = newNode(5);
	root->firstChild->firstChild->nextSibling = newNode(6);
	printf("\nSum of all nodes are %d", sumAll(root));

}