/**
 * Union and Intersection of 2 Linked List
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

node* intersection(node *h1, node* h2)
{
    unordered_set<int> s;
    while(h1)
    {
        s.insert(h1->data);
        h1=h1->next;
    }

    node *h3= NULL, *newN, *curr;
    while(h2)
    {
        if(s.find(h2->data) != s.end())
        {
            newN = newNode(h2->data);
            if(h3 == NULL)
            {
                h3 = newN;
                curr = h3;
            }
            else
            {
                curr->next = newN;
                curr = curr->next;
            }
        }
        h2=h2->next;
    }
    return h3;
}

node* unionL(node *h1, node* h2)
{
    unordered_set<int> s;
    while(h1)
    {
        s.insert(h1->data);
        h1=h1->next;
    }

    while(h2)
    {
        s.insert(h2->data);
        h2=h2->next;
    }

    node *h3 = NULL, *curr, *newN;
    for (auto it=s.begin(); it != s.end();it++)
    {
        newN = newNode(*it);
        if(h3 == NULL)
        {
            h3 = newN;
            curr = h3;
        }
        else
        {
            curr->next = newN;
            curr = curr->next;
        }
    }
    return h3;
}

int main()
{
    node * h = NULL;
    h = newNode(1);
    h->next = newNode(5);
    h->next->next = newNode(10);
    h->next->next->next = newNode(11);
    h->next->next->next->next = newNode(15);

    node * h1 = NULL;
    h1 = newNode(2);
    h1->next = newNode(5);
    h1->next->next = newNode(10);
    h1->next->next->next = newNode(13);
    h1->next->next->next->next = newNode(15);
    print(h);

    print(h1);

    node *h3 = unionL(h, h1);
    cout<<"Union"<<endl;
    print(h3);

    node *h4 = intersection(h, h1);
    cout<<"Intersection"<<endl;
    print(h4);
}
