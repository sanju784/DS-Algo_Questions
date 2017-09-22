/**
 * merge 2 sorted Linked List
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
        cout<<h->data<<" ";
        h=h->next;
    }
    cout<<endl;
}

node* merge(node *a, node *b)
{
    node * result = NULL;
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    if(a->data < b->data)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

int main()
{
    node * h = NULL;
    h = newNode(1);
    h->next = newNode(3);
    h->next->next = newNode(7);
    h->next->next->next = newNode(8);
    h->next->next->next->next = newNode(9);
    print(h);

    node * h1 = NULL;
    h1 = newNode(2);
    h1->next = newNode(3);
    h1->next->next = newNode(4);
    h1->next->next->next = newNode(5);
    print(h1);

    node *h2 = merge(h, h1);
    print(h2);
}
