/**
 * Alternate split of Linked List
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

void split(node *h, node **h1, node **h2)
{
    node *curr = h, *temp, *curr1, *curr2;
    int c =0;
    while(h)
    {
        if(c%2 == 0){
        if(*h1 == NULL)
        {
            *h1 = newNode(h->data);
            curr1 = *h1;
            h = h->next;
        }else
        {
            curr1->next = newNode(h->data);
            curr1 = curr1->next;
            h = h->next;
        }
        }else{
        if(*h2 == NULL)
        {
            *h2 = newNode(h->data);
            curr2 = *h2;
            h = h->next;
        }else
        {
            curr2->next = newNode(h->data);
            curr2 = curr2->next;
            h = h->next;
        }
        }
        c++;
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
    node *h1 = NULL, *h2 = NULL;
    split(h, &h1, &h2);
    print(h1);
    print(h2);
}
