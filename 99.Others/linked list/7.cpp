/**
 * Remove duplicates from unsorted Linked List
 *
 * compile by g++ -std=c++0x 7.cpp
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
        cout<<h->data<<" ";
        h=h->next;
    }
    cout<<endl;
}

void remove(node *h)
{
    unordered_set<int> s;
    node *prev, *curr =h;
    while(curr)
    {
        if(s.find(curr->data) == s.end())
        {
            s.insert(curr->data);
            prev = curr;
        }
        else
        {
            prev->next = curr->next;
            free(curr);
        }
        curr = prev->next;
    }
}

int main()
{
    node * h = NULL;
    h = newNode(1);
    h->next = newNode(2);
    h->next->next = newNode(3);
    h->next->next->next = newNode(2);
    h->next->next->next->next = newNode(1);
    print(h);

    remove(h);
    print(h);
}
