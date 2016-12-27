/*********************************************
*
*  Create BST from singly linked list
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
  int data;
  struct list *next;
} node;

typedef struct tree{
  int data;
  struct tree *left;
  struct tree *right;
} tnode;

void insertAtFirst(node **h , int n) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = n;
    newNode->next = *h;
    *h = newNode;
}

tnode *newNode(int val) {
  tnode *newN = (tnode*)malloc(sizeof(tnode));
  newN->data = val;
  newN->left = NULL;
  newN->right = NULL;
  return newN;
}

int displaynCountList(node *h) {
  int count = 0;
  while(h != NULL) {
    printf("%d ", h->data);
    h = h->next;
    count++;
  }
  return count;
}

void inorder(tnode *root) {
  if(root) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

//create list by recursively finding middle node
tnode* convertListtoTree2(node **h, int start, int end) {
    if(start > end)
        return NULL;
    int mid = start + (end - start) /2;
    tnode *left = convertListtoTree(h, start, mid -1);
    tnode *root = newNode((*h)->data);
    root->left = left;
    *h = (*h)->next;
    root->right = convertListtoTree(h, mid + 1, end);
    return root;
}

tnode* convertListtoTree(node **h, int n) {
    if(n <= 0)
        return NULL;
    tnode *left = convertListtoTree(h, n/2);
    tnode *root = newNode((*h)->data);
    root->left = left;
    *h = (*h)->next;
    root->right = convertListtoTree(h, n-n/2-1);
    return root;
}

void main() {
  node *head = NULL;
  insertAtFirst(&head, 7);
  insertAtFirst(&head, 6);
  insertAtFirst(&head, 5);
  insertAtFirst(&head, 4);
  insertAtFirst(&head, 3);
  insertAtFirst(&head, 2);
  insertAtFirst(&head, 1);
  int n = displaynCountList(head);

  tnode *root = convertListtoTree(&head, n);
  printf("\nInorder traversal of tree ");
  inorder(root);

  tnode *root2 = convertListtoTree2(&head, 0, n-1);
}
