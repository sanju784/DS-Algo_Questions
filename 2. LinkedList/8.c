/*********************************************
*
*  Find the Middle of a Singly Linked List
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

void display(node *h) {
  node *temp = h;
  while(temp != NULL) {
    printf("-->%d", temp->data);
    temp = temp->next;
  }
}

//using 2 pointers
int getMiddle (node *h) {
  node *slowPtr = h;
  node *fastPtr = h;
  node *prev;
  while (fastPtr && fastPtr->next) {
    prev = slowPtr;
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  if(fastPtr == NULL)
    return prev->data;
  else
    return slowPtr->data;
}

void main() {
  node *head = NULL;
  addNode(&head, 5);
  addNode(&head, 15);
  addNode(&head, 25);
  addNode(&head, 35);
  addNode(&head, 45);
  addNode(&head, 55);
  display(head);
  if (head != NULL) {
    printf("\nThe middle value of List is %d\n", getMiddle(head));
  } else {
    printf("\nThe List is empty.\n");
  }
}
