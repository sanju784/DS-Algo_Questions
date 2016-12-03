/*********************************************
*
*  Find Union and Intersection of 2 BST
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
 
typedef struct tree{
  int data;
  struct tree *left;
  struct tree *right;
} node;
 
node *newNode(int val) {
  node *newN = (node*)malloc(sizeof(node));
  newN->data = val;
  newN->left = NULL;
  newN->right = NULL;
  return newN;
}
 
node *create() {
  node *p = newNode(4);
  p->left = newNode(2);
  p->right = newNode(6);
  p->left->left = newNode(1);
  p->left->right = newNode(3);
  p->right->left = newNode(5);
  p->right->right = newNode(7);
  return p;
}
 
node *create2() {
  node *p = newNode(5);
  p->left = newNode(1);
  p->right = newNode(7);
  return p;
}
 
void inorder(node *root) {
  if(root) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}
 
void storeInorder(node *root, int inorder[], int *i) {
  if(root == NULL)
    return;
  storeInorder(root->left, inorder, i);
  inorder[*i] = root->data;
  (*i)++;
  storeInorder(root->right, inorder, i);
}
 
void mergeArr(int a[], int b[], int m, int n, int resArr[]) {
 
  int i=0, j=0, k=0;
  while(i < m && j < n) {
    if(a[i] < b[j]) {
        resArr[k] = a[i];
        i++;
    } else {
      resArr[k] = b[j];
      j++;
    }
    k++;
  }
  while(i < m) {
    resArr[k] = a[i];
    i++;
    k++;
  }
  while(j < n) {
    resArr[k] = b[j];
    j++;
    k++;
  }
}
 
node* arrToBST(int arr[], int start, int end) {
  if(start > end)
    return NULL;
  int mid = (start + end) /2;
  node *root = newNode(arr[mid]);
 root->left = arrToBST(arr, start, mid-1);
  root->right = arrToBST(arr, mid+1, end);
  return root;
}
 
node* mergeTrees(node *r1, node *r2, int m, int n) {
  int a[m];
  int i = 0;
  storeInorder(r1, a, &i);
 
  int b[n];
  int j = 0;
  storeInorder(r2, b, &j);
 
  int resArr[m+n];
  mergeArr(a, b, m, n, resArr);
  return arrToBST(resArr, 0, m+n-1);
}

void arrayIntersection(int a[], int b[], int m, int n) {
  int i=0, j=0, k=0;
  while (i < m && j < n) {
    if(a[i] == b[j]) {
      printf("%d ", a[i]);
      i++;
      j++;
    }
    if(a[i] < b[j])
      i++;
    if(a[i] > b[j])
      j++;
  }
}

void intersectTree(node *r1, node *r2, int m, int n) {
  int a[m];
  int i = 0;
  storeInorder(r1, a, &i);
 
  int b[n];
  int j = 0;
  storeInorder(r2, b, &j);
  arrayIntersection(a, b, m, n);
}
 
int main() {
  node *root1;
  root1 = create();
  printf("\nInorder root1 ");
  inorder(root1);

  node *root2;
  root2 = create2();
  printf("\nInorder root2 ");
  inorder(root2);
 
  node *res = mergeTrees(root1, root2, 7, 3);
 
  printf("\nInorder of merged tree is ");
  inorder(res);

  printf("\nThe Trees Intersection is ");
  intersectTree(root1, root2, 7, 3);
  return 0;
}