/*********************************************
*
*  Sorting Linked List with QuickSort
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

node *getTail(node *h) {
	while(h != NULL && h->next != NULL)
		h = h->next;
	return h;
}

node *partition(node *head, node *end, node **newHead, node **newEnd) {
	node *pivot = end;
	node *prev = NULL, *curr = head, *tail=pivot;

	while(curr != pivot){
		if(curr->data < pivot->data){
			if(*newHead == NULL)
				*newHead = curr;
			prev = curr;
			curr = curr->next;
		} else {
			if(prev)
				prev->next = curr->next;
			node* temp = curr->next;
			curr->next = NULL;
			tail->next = curr;
			tail = curr;
			curr = temp;
		}
	}

	if(*newHead == NULL)
		*newHead = pivot;
	*newEnd = tail;
	return pivot;
}

node *quickSortRec(node *head, node *end) {
	if(!head || head == end)
		return head;
	node *newHead = NULL, *newEnd = NULL;

	node *pivot = partition(head, end, &newHead, &newEnd);

	if(newHead != pivot)
	{
		node *temp = newHead;
		while(temp->next != pivot)
			temp = temp->next;
		temp->next = NULL;

		newHead = quickSortRec(newHead, temp);
		temp = getTail(newHead);
		temp->next = pivot;
	}
	pivot->next = quickSortRec(pivot->next, newEnd);
	return newHead;
}

void quickSort(node **head) {
	*head = quickSortRec(*head, getTail(*head));
	return;
}

void main() {
	node *head = NULL;
	int a[]={4,2,7,8,1,3};
	int i;
	for(i=0;i<6;i++)
		insertAtFirst(&head, a[i]);

	//mergeSort(&head);
	quickSort(&head);
	printList(head);
}