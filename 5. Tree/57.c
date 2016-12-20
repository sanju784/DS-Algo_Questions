/*********************************************
*
*  Create BST from sorted array
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

void inorder(node *root) {
	if(root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

node *createBSTfromArr(int a[], int start, int end) {
	if(start > end)
		return NULL;
	int mid = (start + end) / 2;
	node *root = newNode(a[mid]);
	root->left = createBSTfromArr(a, start, mid-1);
	root->right = createBSTfromArr(a, mid+1, end);

	return root;
}

void main() {
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	node *root = createBSTfromArr(arr, 0, n-1);
	printf("\n Inorder traversal of tree is ");
	inorder(root);
}