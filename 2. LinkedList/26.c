/*********************************************
*
*  Sort a Linked List
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int data;
	struct list *next;
} node;

void addNode(node **h, int n) {
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = n;
	newNode->next = *h;
	*h = newNode;
}

void print(node *h) {
	while(h != NULL) {
		printf("%d", h->data);
		h = h->next;
		if(h != NULL)
			printf("-->");
	}
}

void sortList(node *h) {
	node *temp1, *temp2, *temp;
	for (temp1 = h; temp1->next->next != NULL; temp1 = temp1->next) {
		int s = temp1->data;
		for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
			if (temp2->data < s) {
				s = temp2->data;
				temp = temp2;
			}
		}
		temp->data = temp1->data;
		temp1->data = s;
	}
}

void main() {
	node *head = NULL;

	addNode(&head, 5);
	addNode(&head, 15);
	addNode(&head, 55);
	addNode(&head, 45);
	addNode(&head, 25);

	print(head);

	sortList(head);
	printf("\n");
	print(head);
}