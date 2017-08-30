/*********************************************
*
*  Search element in binary tree - recursion
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree{
  int data;
  struct tree *left, *right;
} node;

node *create() {
  node* p;
  int n;
  printf("\nEnter data (Enter -1 if no child node) : ");
  scanf("%d", &n);
  if(n == -1) {
    return NULL;
  }
  p = (node*)malloc(sizeof(node));
  p->data = n;
  printf("\nEnter left child of %d", n);
  p->left = create();
  printf("\nEnter right child of %d", n);
  p->right = create();
  return p;
}

bool find(node *p, int n) {
  int val;
  int left, right;
  if(p!=NULL)
  {
      val = p->data;
      if(val == n)
        return true;
      left = find(p->left, n);
      if(left == true)
        return true;
      else
      {
          right = find(p->right, n);
          if(right == true)
            return true;
      }
  }
  return false;
}

void main() {
  node *root;
  root = create();
  int n;
  printf("\nEnter the data you want to search ");
  scanf("%d", &n);
  bool res = find(root, n);
  if(res)
    printf("\n%d exists in tree.", n);
  else
    printf("\n%d does not exist in tree.", n);
}
