/**
 * Remove duplicates from a sorted Linked List
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

void remove(node *h)
{
    node *curr = h;
    node *next;
    while(curr->next)
    {
        if(curr->data == curr->next->data)
        {
            next = curr->next->next;
            free(curr->next);
            curr->next = next;
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main()
{
    node * h = NULL;
    h = newNode(1);
    h->next = newNode(1);
    h->next->next = newNode(3);
    h->next->next->next = newNode(4);
    h->next->next->next->next = newNode(4);
    print(h);

    remove(h);
    print(h);
}
