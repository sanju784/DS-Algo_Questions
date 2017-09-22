/**
 * Delete alternate node Linked List
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* newNode(int n)
{
    node *newN = (node*)malloc(sizeof(node));
    newN->data = n;
    newN->next = NULL;
    return newN;
}

void print(node *h)
{
    while(h)
    {
        printf(" %d", h->data);
        h=h->next;
    }
    printf("\n");
}

void deleteN(node *h)
{
    node *curr = h, *temp;
    while(curr && curr->next)
    {
        temp = curr->next;
        curr->next = temp->next;
        free(temp);
        curr = curr->next;
    }
}

int main()
{
    node * h = NULL;
    h = newNode(1);
    h->next = newNode(2);
    h->next->next = newNode(3);
    h->next->next->next = newNode(4);
    h->next->next->next->next = newNode(5);
    print(h);
    deleteN(h);
    print(h);
}
