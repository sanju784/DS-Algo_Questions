/**
 * Reverse Linked List in k
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

    //next is now at k+1 th position so start next reversal from here
    if(next != NULL)
        head->next = reverseK(next, k);

    //the function ends when curr is null, in this case
    //prev will point to last node which will be the new header
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
    print(h);
    int k = 3;
    h = reverseK(h, k);
    print(h);
}
