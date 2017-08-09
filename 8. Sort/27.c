/*********************************************
*
*  Sorting a Linked List
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

node* merge(node *a, node*b);

void listSplit(node *source, node **front, node **back);

void mergeSort(node **head) {
	node* h = *head;
	node *a, *b;
	if(h == NULL || h->next == NULL)
		return;
	listSplit(h, &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	*head = merge(a,b);
}

node* merge(node *a, node*b) {
	node *result = NULL;
	if(a==NULL) return b;
	if(b==NULL) return a;
	if(a->data <= b->data){
		result = a;
		result->next = merge(a->next, b);
	} else {
		result = b;
		result->next = merge(a, b->next);
	}
	return result;
}

void listSplit(node *source, node **front, node **back) {
	node *fast, *slow;
	if(source == NULL && source->next == NULL) {
		*front = source;
		*back = NULL;
	} else {
		slow = source;
		fast = source->next;
		while(fast != NULL){
			fast = fast->next;
			if(fast != NULL) {
			  slow = slow->next;
			  fast = fast->next;
		    }
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}

void main() {
	node *head = NULL;
	int a[]={4,2,7,8,1,3};
	int i;
	for(i=0;i<6;i++)
		insertAtFirst(&head, a[i]);

	mergeSort(&head);
	printList(head);
}