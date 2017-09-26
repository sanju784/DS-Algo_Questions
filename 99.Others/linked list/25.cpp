/**
 * Arrange Linked List in saw tooth form
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

void rearrange(node *h)
{
    bool flag = true;
    node *curr = h;
    while(curr->next)
    {
        if(flag)
        {
            if(curr->data > curr->next->data)
            swap(curr->data, curr->next->data);
        } else
        {
            if(curr->next->data > curr->data)
            swap(curr->data, curr->next->data);
        }
        curr = curr->next;
        flag = !flag;
    }
}

int main()
{
    node *h = NULL;
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
