/**
 * Segregate even and odd nodes
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

//here inserting even one at start, but here order will be broken
//insert at last
//made two new linked list of even and odd
void evenOdd(node **head)
{
    node *curr = *head, *prev = NULL;
    while(curr)
    {
        if(curr->data%2 == 0 && prev)
        {
            prev->next = curr->next;
            curr->next = *head;
            *head = curr;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

int main()
{
    node * h = NULL;
    h = newNode(12);
    h->next = newNode(15);
    h->next->next = newNode(10);
    h->next->next->next = newNode(11);
    h->next->next->next->next = newNode(5);
    h->next->next->next->next->next = newNode(6);
    h->next->next->next->next->next->next = newNode(2);
    h->next->next->next->next->next->next->next = newNode(3);

    print(h);
    evenOdd(&h);
    print(h);
}
