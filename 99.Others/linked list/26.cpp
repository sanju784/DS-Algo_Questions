/**
 * Add 1 to number represented by Linked List
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

void add(node *h, int *carry)
{
    if(h->next == NULL)
    {
        int n = h->data + 1;
        h->data = n%10;
        *carry = n/10;
        return;
    }
    add(h->next, carry);
    int n = h->data + (*carry);
    h->data = n%10;
    *carry = n/10;
}

int main()
{
    node *h = NULL;
    h = newNode(9);
    h->next = newNode(9);
    h->next->next = newNode(9);
    h->next->next->next = newNode(9);
    print(h);

    int carry = 0;
    add(h, &carry);
    if(carry != 0)
    {
        node *newN = newNode(carry);
        newN->next = h;
        h = newN;
    }
    print(h);
}
