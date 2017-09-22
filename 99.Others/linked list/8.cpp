/**
 * swap Linked List elements pair wise
 *
 * I/P - 1->2->3->4->5
 * O/P - 2->1->4->3->5
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

void swapPair(node *h)
{
    while(h && h->next)
    {
        swap(h->data, h->next->data);
        h=h->next->next;
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

    swapPair(h);
    print(h);
}
