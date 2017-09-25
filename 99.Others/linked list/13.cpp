/**
 * Merge Sort of Linked List
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
    node *fast, *slow;
    if(h == NULL || h->next == NULL)
    {
        *h1 = h;
        *h2 = NULL;
    }
    else{
        slow = h;
        fast = h->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        *h1 = h;
        *h2 = slow->next;
        slow->next = NULL;
    }
}

node *merge(node *a, node *b)
{
    node *result = NULL;
    if(a== NULL)
        return b;
    if(b== NULL)
        return a;

    if(a->data <= b->data)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else{
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

//Recursive function to first split the linked list by mid
//then merging the linked list in sorted way
void mergeSort(node **head)
{
    node *h = *head;
    if(h == NULL || h->next == NULL)
        return;
    node *a, *b;
    split(h, &a, &b);
    mergeSort(&a);
    mergeSort(&b);

    *head = merge(a,b);
}

int main()
{
    node * h = NULL;
    h = newNode(1);
    h->next = newNode(3);
    h->next->next = newNode(2);
    h->next->next->next = newNode(9);
    h->next->next->next->next = newNode(5);
    h->next->next->next->next->next = newNode(7);
    print(h);
    mergeSort(&h);
    print(h);
}
