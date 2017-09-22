/**
 * Intersection of 2 sorted Linked List
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

node* intersection(node *h1, node *h2)
{
    node *h3 = NULL, *curr, *newN;
    while(h1 && h2)
    {
        if(h1->data == h2->data)
        {
            newN = newNode(h1->data);
            if(h3 == NULL)
            {
                h3 = newN;
                curr = h3;
            }else{
                curr->next = newN;
                curr = curr->next;
            }
            h1=h1->next;
            h2=h2->next;
        }
        else if(h1->data < h2->data)
            h1 = h1->next;
        else
            h2 = h2->next;
    }

    return h3;
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

    node * h2 = NULL;
    h2 = newNode(1);
    h2->next = newNode(3);
    h2->next->next = newNode(5);
    h2->next->next->next = newNode(7);
    print(h2);

    node *h3 = rec(h, h2);
    print(h3);
}

/**

// By Recursion

node *rec(node* h1, node *h2)
{
    if(h1 == NULL || h2 == NULL)
        return NULL;

    if(h1->data < h2->data)
        return rec(h1->next, h2);

    if(h1->data > h2->data)
        return rec(h1, h2->next);

    node *newN = newNode(h1->data);
    newN->next = rec(h1->next, h2->next);
    return newN;
}

*/
