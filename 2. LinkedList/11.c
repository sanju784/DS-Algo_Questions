/*********************************************
*
*  Merge 2 sorted Linked List to make a new sorted List
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

node* mergeList (node *h1, node *h2) {
  node *h3 = NULL;
  //here pointer to last node of result List is needed to add new nodes after it
  //as we cannot move head of resulting List as doing so we cannot get head back
  node *lastPtr;
  if(h1 == NULL) {
    h3 = h2;
    return h3;
  }
  if (h2 == NULL) {
    h3 = h1;
    return h3;
  }
  while (h1 != NULL && h2 != NULL) {
    if(h1->data < h2->data) {
      if(h3 == NULL){
        h3 = h1;
        lastPtr = h3;
      } else {
        lastPtr->next = h1;
        lastPtr = lastPtr->next;
      }
      h1 = h1->next;
    } else {
      if(h3 == NULL) {
        h3 = h2;
        lastPtr = h3;
      } else {
        lastPtr->next = h2;
        lastPtr = lastPtr->next;
      }
      h2 = h2->next;
    }
    lastPtr->next = NULL;
  }
  if(h1 == NULL) {
    lastPtr->next = h2;
  }
  if(h2 == NULL) {
    lastPtr->next = h1;
  }
  
  return h3;
}

void main() {
  node *head1 = NULL;
  node *head2 = NULL;
  addNode(&head1, 55);
  addNode(&head1, 45);
  addNode(&head1, 35);
  addNode(&head1, 25);
  addNode(&head1, 15);
  display(head1);
  addNode(&head2, 30);
  addNode(&head2, 20);
  addNode(&head2, 10);
  printf("\n\n");
  display(head2);
  node *head3 = mergeList(head1, head2);
  printf("\n\nThe list after merge is \n");
  display(head3);
}
