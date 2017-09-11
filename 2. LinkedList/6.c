/*********************************************
*
*  Reverse a Linked List
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list *next;
} node;

void addNode (node **h, int n) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = n;
    newNode->next = *h;
    *h = newNode;
}

void print(node *h) {
  while(h != NULL) {
    printf("-->%d", h->data);
    h = h->next;
  }
}

void reverseList(node **h) {
  node* prev = NULL;
  node *curr = *h;
  node *next;
  while(curr != NULL)
  {
    next = curr->next; //as current next value will change first so saving it first
    curr->next = prev; //current will point to previous
    prev = curr;       //moving prev to current
    curr = next;       //moving current to next
  }
  *h = prev;
}

void main() {
  node *head = NULL;
  addNode(&head, 5);
  addNode(&head, 15);
  addNode(&head, 25);
  addNode(&head, 35);
  addNode(&head, 45);
  addNode(&head, 55);
  print(head);
  reverseList(&head);
  printf("\n");
  print(head);
}
