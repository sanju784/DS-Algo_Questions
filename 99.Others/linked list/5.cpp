/**
 * Check if Linked List is Palindrome
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

int palindrome(node *h)
{
    node *fast = h, *slow = h;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *mid = slow;

    node *prev = NULL;
    node *curr = mid;
    node *next;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    node *h2 = prev;

    while(h && h2)
    {
        if(h->data != h2->data)
            return false;
        h=h->next;
        h2=h2->next;
    }
    return true;
}

int main()
{
    node * h = NULL;
    h = newNode(1);
    h->next = newNode(2);
    h->next->next = newNode(3);
    h->next->next->next = newNode(3);
    h->next->next->next->next = newNode(2);
    h->next->next->next->next->next = newNode(1);
    print(h);

    cout<<palindrome(h);
}
