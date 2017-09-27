/**
 * Quick Sort of DLL
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
} node;

void insertAtFirst(node **h, int n)
{
    node *newN = (node*)malloc(sizeof(node));
    newN->data = n;
    newN->prev = NULL;
    newN->next = *h;
    if(*h != NULL)
    {
        (*h)->prev = newN;
    }
    *h = newN;
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

node* getLast(node *h)
{
    while(h->next)
        h = h->next;
    return h;
}

node *partition(node *h, node* l)
{
    int pivot = l->data;

    node *i = h->prev;

    for(node *j=h; j != l; j=j->next)
    {
        if(j->data <= pivot)
        {
            i = (i == NULL)?h:i->next;
            swap(i->data, j->data);
        }
    }
    i = (i == NULL)?h:i->next;
    swap(i->data, l->data);
    return i;
}

void quickSortUtil(node *h, node *l)
{
    if(l != NULL && h != l && h != l->next)
    {
        node *p = partition(h, l);
        quickSortUtil(h, p->prev);
        quickSortUtil(p->next, l);
    }
}

void quickSort(node *h)
{
    //get last node of Linked List
    node *l = getLast(h);
    quickSortUtil(h, l);
}

int main()
{
    node *h = NULL;
    insertAtFirst(&h, 10);
    insertAtFirst(&h, 5);
    insertAtFirst(&h, 15);
    insertAtFirst(&h, 25);
    insertAtFirst(&h, 20);
    print(h);
    quickSort(h);
    print(h);
}
