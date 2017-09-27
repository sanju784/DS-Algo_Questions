/**
 * Merge Sort of DLL
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

node *split(node *h)
{
    node *slow = h, *fast = h;
    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *temp = slow->next;
    slow->next = NULL;
    return temp;
}

node *merge(node *first, node *second)
{
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    if(first->data < second->data)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

node* mergeSort(node *h)
{
    if(h == NULL || h->next == NULL)
        return h;

    node *second = split(h);
    h = mergeSort(h);
    second = mergeSort(second);

    return merge(h, second);
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
    h = mergeSort(h);
    print(h);
}
