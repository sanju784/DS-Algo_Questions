/*********************************************
*
*  Convert Sorted DLL to balanced BST
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct DLL{
  int data;
  struct DLL *prev;
  struct DLL *next;
} node;

void insertAtFirst(node **h , int n) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = n;
    if(*h == NULL) {
        *h = newNode;
        newNode->next = newNode->prev = NULL;
    } else {
      newNode->next = *h;
      newNode->prev = NULL;
      *h = newNode;
    }
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

void inorder(node *root) {
  if(root) {
    inorder(root->prev);
    printf("%d ", root->data);
    inorder(root->next);
  }
}

node* convertListtoTree(node **h, int n) {
    if(n <= 0)
        return NULL;
    node *left = convertListtoTree(h, n/2);
    node *root = *h;
    root->prev = left;
    *h = (*h)->next;
    root->next = convertListtoTree(h, n-n/2-1);
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

  node *root = convertListtoTree(&head, n);
  printf("\nInorder traversal of tree ");
  inorder(root);
}
