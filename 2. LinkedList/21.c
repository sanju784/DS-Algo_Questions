/*********************************************
*
*  Find the sqrt(n) element of a Linked List
*  n is number of elements of a Linked List
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

node* getRootNode(node *h) {
  if (h == NULL)
    return NULL;
  node *root_node = NULL, *temp = h;
  int i = 1, j = 1;
  for(; temp != NULL; temp = temp->next) {
    if(i == j*j) {
      if(root_node == NULL)
        root_node = h;
      else
        root_node = root_node->next;
      j++;
    }
    i++;
  }
  return root_node;
}

/**
 * Another fuction to get root node
 * moving root node to next when number with perfect square comes
 */
node* getRootNode2(node *h) {
	if (h == NULL)
      return NULL;
	node *sqrtNode = h;
	int i = 1, s = 1;
	while(h) {
		if(floor(sqrt(i)) > s) {
			s++;
			sqrtNode = sqrtNode->next;
		}
		i++;
		h = h->next;
	}
	return sqrtNode;
}

void main() {
  node *head = NULL;
  node *root_node;
  addNode(&head, 55);
  addNode(&head, 45);
  addNode(&head, 35);
  addNode(&head, 25);
  addNode(&head, 15);
  addNode(&head, 5);
  display(head);
  root_node = getRootNode(head);
  if(root_node) {
    printf("\n\nThe root node is %d.", root_node->data);
  } else {
    printf("The list is empty.");
  }
}
