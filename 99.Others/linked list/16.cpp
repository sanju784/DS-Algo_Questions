/**
 * Delete a node if it has greater value on right
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

//Reversing the list, the maximum will come to left so making traversal easy
//keeping maximum till now, deleting node less than it on right, updating max when new max comes
//reversing again
node* delRight(node *head)
{
    node *prev = NULL, *curr = head, *next;

    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    curr = head;
    int max = INT_MIN;

    while(curr)
    {
        if(curr->data > max)
        {
            max = curr->data;
            prev = curr;
            curr = curr->next;
        }
        else
        {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
    }

    prev = NULL, curr = head, next;

    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    h = delRight(h);
    print(h);
}
