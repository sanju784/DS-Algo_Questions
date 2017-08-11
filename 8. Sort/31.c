/*********************************************
*
*  Merge k-sorted Linked List
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void insertAtFirst(node **head, int n) {
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}

void printList(node* head) {
	while(head)
	{
		printf("-->%d", head->data);
		head = head->next;
	}
}

node *merge(node *a, node *b) {
	node *result = NULL;
	if(a == NULL) return b;
	if(b == NULL) return a;
	if(a->data <= b->data){
		result = a;
		result->next = merge(a->next, b);
	} else {
		result = b;
		result->next = merge(a, b->next);
	}
	return result;
}

node *mergeKList(node* arr[], int last) {
  while(last != 0) {
	int i=0, j=last;
	while(i<j) {
		arr[i] = merge(arr[i], arr[j]);
		i++;
		j--;
		if(i>=j)
			last = j;
	}
  }
  return arr[0];
}

void main() {
	int k = 3;
	node *head[3] = {NULL, NULL, NULL};
	int a1[]={9,8,4,2};
	int a2[]={7,5,3,1};
	int a3[]={12,10,7,6};
	int i;
	for(i=0;i<4;i++) {
		insertAtFirst(&head[0], a1[i]);
		insertAtFirst(&head[1], a2[i]);
		insertAtFirst(&head[2], a3[i]);
	}
	node *resHead = mergeKList(head, k-1);
	printList(resHead);
}