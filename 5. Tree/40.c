/*********************************************
*
*  Count number of siblings in a generic tree
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

int countSibling(node *root) {
	int count = 0;
	while (root->nextSibling) {
		count++;
		root = root->nextSibling;
	}
	return count;
}

void main () {
	node* root;
	root = newNode(1);
	root->firstChild = newNode(2);
	root->firstChild->nextSibling = newNode(3);
	root->firstChild->nextSibling->nextSibling = newNode(4);
	root->firstChild->firstChild = newNode(5);
	root->firstChild->firstChild->nextSibling = newNode(6);
	printf("\nTotal siblings next to %d are %d", root->firstChild->data, countSibling(root->firstChild));

}