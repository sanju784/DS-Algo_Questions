/*********************************************
*
*  Reverse Linked List in block of k
*  Input : 1->2->3->4->5->6->7->8->9->X
*  If k = 3
*  Output : 3->2->1->6->5->4->9->8->7->X
*  If k = 4
*  Output : 4->3->2->1->8->7->6->5->9->X
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
  while(h != NULL) {
    printf("-->%d", h->data);
    h = h->next;
  }
}

node* reverseBlock(node *h, int k) {
  node *prev = NULL;
  node *current = h;
  node *next = NULL;
  int count = 0;
  while (current != NULL && count < k) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
  }
  if(next != NULL) 
    h->next = reverseBlock(next, k);
  return prev;
}

void main() {
  node *head = NULL;
  int k;
  addNode(&head, 55);
  addNode(&head, 45);
  addNode(&head, 35);
  addNode(&head, 25);
  addNode(&head, 15);
  addNode(&head, 5);
  display(head);
  printf("\n\nEnter the group number in which you want to reverse list : ");
  scanf("%d", &k);
  head = reverseBlock(head, k);
  printf("\n\n");
  display(head);
}
