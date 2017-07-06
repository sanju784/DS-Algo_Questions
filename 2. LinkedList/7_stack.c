/*********************************************
*
*  Find the Merge Point of two Singly Linked List
*  Using Stack
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void mergeList(node *h1, node *h2) {
  while(h2->next != NULL) {
    h2 = h2->next;
  }
  int i;
  for(i = 0;i < 3;i++) {
    h1 = h1->next;
  }
  h2->next = h1;
}

int getLength(node *h) {
  int count = 0;
  while (h && h->next) {
    count++;
    h = h->next;
  }
  return count;
}

/**
 * Saving the address of node in Stack
 * Comparing Stack and returning when the value are same
 */
node* mergePoint(node *h1, node *h2) {
  node *stack1[10], *stack2[10];
  int i = 0, j = 0;
  while(h1 != NULL) {
	  stack1[i++] = h1;
	  h1 = h1->next;
  }
  
  while(h2 != NULL) {
	  stack2[j++] = h2;
	  h2 = h2->next;
  }
  
  int k = 0;
  while(j >= 0) {
	  if(stack1[--j] == stack2[--j])
		  return stack1[j];
  }
  return NULL;
}

void main() {
  node *head1 = NULL;
  node *head2 = NULL;
  addNode(&head1, 5);
  addNode(&head1, 15);
  addNode(&head1, 25);
  addNode(&head1, 35);
  addNode(&head1, 45);
  addNode(&head1, 55);
  display(head1);
  addNode(&head2, 10);
  addNode(&head2, 20);
  mergeList(head1, head2);
  printf("\n\n");
  display(head2);
  node * res = mergePoint(head1, head2);
  if (res) {
    printf("\n\nThe merge point of the above List is at %d", res->data);
  } else {
    printf("\n\nThere is no merge point in this list.");
  }
}