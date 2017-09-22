/**
 * Delete a Linked List
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

void deleteN(node **h)
{
    node *curr = *h;
    node *next;
    while(curr)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *h = NULL;
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

    deleteN(&h);
    print(h);
}
