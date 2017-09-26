/**
 * Point to next higher value of Linked List
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* next;
    struct node* random;
} node;

node* newNode(int n)
{
    node *newN = (node*)malloc(sizeof(node));
    newN->data = n;
    newN->next = NULL;
    newN->random = NULL;
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
    if(h == NULL || h->next == NULL || h->random == NULL)
    {
        *h1 = h;
        *h2 = NULL;
    }
    else{
        slow = h;
        fast = h->random;
        while(fast && fast->random)
        {
            slow = slow->random;
            fast = fast->random->random;
        }
        *h1 = h;
        *h2 = slow->random;
        slow->random = NULL;
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
        result->random = merge(a->random, b);
    }
    else{
        result = b;
        result->random = merge(a, b->random);
    }
    return result;
}

//Recursive function to first split the linked list by mid
//then merging the linked list in sorted way
void mergeSort(node **head)
{
    node *h = *head;
    if((h == NULL) || (h->random == NULL))
        return;
    node *a, *b;
    split(h, &a, &b);
    mergeSort(&a);
    mergeSort(&b);

    *head = merge(a,b);
}

//make random point to next element and
//then merge sort List by random pointer
node* nextHigh(node *h)
{
    node *temp = h;
    while(temp)
    {
        temp->random = temp->next;
        temp->next = temp->next;
    }
    mergeSort(&h);
    return h;
}

void printByRandom(node *h)
{
    while(h)
    {
        printf(" %d", h->data);
        h=h->random;
    }
    printf("\n");
}

int main()
{
    node *h = NULL;
    h = newNode(4);
    h->next = newNode(3);
    h->next->next = newNode(5);
    h->next->next->next = newNode(1);
    h->next->next->next->next = newNode(2);
    print(h);
    node *h2 = nextHigh(h);
    printByRandom(h2);
}
