/**
 * Merge two sorted Linked list such that resulting list is in descending
 */

#include <bits/stdc++.h>
using namespace std;

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

void insertAtBegin(node **h, int n)
{
    node* newN = newNode(n);
    newN->next = *h;
    *h = newN;
}

//inserting smaller node at begin of list
node *merge(node* h1, node *h2)
{
    node *h3 = NULL;

    while(h1 && h2)
    {
        if(h1->data < h2->data)
        {
            insertAtBegin(&h3, h1->data);
            h1 = h1->next;
        }
        else
        {
            insertAtBegin(&h3, h2->data);
            h2 = h2->next;
        }
    }

    while(h1)
    {
        insertAtBegin(&h3, h1->data);
        h1 = h1->next;
    }

    while(h2)
    {
        insertAtBegin(&h3, h2->data);
        h2 = h2->next;
    }
    return h3;
}

int main()
{
    node *h = NULL;
    h = newNode(1);
    h->next = newNode(3);
    h->next->next = newNode(7);
    print(h);

    node *h1 = NULL;
    h1 = newNode(2);
    h1->next = newNode(4);
    h1->next->next = newNode(6);

    print(h1);
    node *h2 = merge(h, h1);
    print(h2);
}
