/**
 * Insertion sort of Linked List
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

void insertInSorted(node **h, node *newN)
{
    if(*h == NULL || newN->data < (*h)->data)
    {
        newN->next = *h;
        *h = newN;
    }

    else
    {
        node *temp = *h;

        while(temp->next != NULL && temp->next->data < newN->data)
        {
            temp = temp->next;
        }
        newN->next = temp->next;
        temp->next = newN;
    }
}

void insertSort(node **h)
{
    node *newH = NULL;
    node *curr = *h;
    while(curr)
    {
        //saving next pointer before as on call of function
        //insertInSorted the current node is removed
        node *next = curr->next;
        insertInSorted(&newH, curr);
        curr = next;
    }
    *h = newH;
}

int main()
{
    node * h = NULL;
    h = newNode(4);
    h->next = newNode(3);
    h->next->next = newNode(5);
    h->next->next->next = newNode(1);
    h->next->next->next->next = newNode(2);
    print(h);

    insertSort(&h);
    print(h);
}
