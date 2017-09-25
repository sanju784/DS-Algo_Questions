/**
 * Reverse Linked List in k alternatively
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

node* reverseK(node *head, int k)
{
    node *prev = NULL, *curr = head, *next;

        int count = 0;
        //reverse k nodes
        while(curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(head)
            head->next = curr;

        count = 0;
        while(curr != NULL && count < k-1)
        {
            curr = curr->next;
            count++;
        }

        if(curr != NULL)
        {
            curr->next = reverseK(curr->next, k);
        }

        return prev;
}

int main()
{
    node * h = NULL;
    h = newNode(1);
    h->next = newNode(2);
    h->next->next = newNode(3);
    h->next->next->next = newNode(4);
    h->next->next->next->next = newNode(5);
    h->next->next->next->next->next = newNode(6);
    h->next->next->next->next->next->next = newNode(7);
    h->next->next->next->next->next->next->next = newNode(8);
    h->next->next->next->next->next->next->next->next = newNode(9);
    print(h);
    int k = 3;
    h = reverseK(h, k);
    print(h);
}
