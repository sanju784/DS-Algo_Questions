/**
 * Flatten a Linked List
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* right;
    struct node* down;
} node;

void push(node** h, int n)
{
    node* newN = (node*)malloc(sizeof(node));
    newN->right = NULL;
    newN->data = n;
    newN->down = *h;
    *h = newN;
}

void print(node *h)
{
    while(h)
    {
        printf(" %d", h->data);
        h=h->down;
    }
    printf("\n");
}

node *merge(node* a, node* b)
{
    if(a==NULL)
        return b;
    if(b== NULL)
        return a;
    node *res;

    if(a->data < b->data)
    {
        res = a;
        res->down = merge(a->down, b);
    }
    else
    {
        res = b;
        res->down = merge(a, b->down);
    }
}

node* flatten(node* h)
{
    if(h == NULL || h->right == NULL)
        return h;

    return merge(h, flatten(h->right));
}

int main()
{
    node * h = NULL;

    push(&h, 30);
    push(&h, 8);
    push(&h, 7);
    push(&h, 5);

    push(&(h->right), 20);
    push(&(h->right), 10);

    push(&(h->right->right), 50);
    push(&(h->right->right), 22);
    push(&(h->right->right), 19);

    push(&(h->right->right->right), 45);
    push(&(h->right->right->right), 40);
    push(&(h->right->right->right), 35);
    push(&(h->right->right->right), 20);

    h=flatten(h);
    print(h);

}
