/**
 * Rearrange List
 * from L1->L2->L3->L4->L5 to L1->L5->L2->L4->L3
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

//find mid point then reverse second half
//and then rearrange list as required
void rearrange(node *h)
{
    if(h == NULL && h->next == NULL)
        return;
    node *h2, *slow = h, *fast = h->next;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    h2 = slow->next;
    slow->next = NULL;
    node *curr = h2, *prev = NULL, *next;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    h2 = prev;

    node* curr1 = h, *next1;
    node* curr2 = h2, *next2;
    while(curr1 && curr2)
    {
        next1 = curr1->next;
        curr1->next = curr2;
        next2 = curr2->next;
        curr2->next = next1;
        curr1=next1;
        curr2=next2;
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
    h->next->next->next->next->next = newNode(6);
    h->next->next->next->next->next->next = newNode(7);
    h->next->next->next->next->next->next->next = newNode(8);
    h->next->next->next->next->next->next->next->next = newNode(9);
    print(h);

    rearrange(h);
    print(h);
}
