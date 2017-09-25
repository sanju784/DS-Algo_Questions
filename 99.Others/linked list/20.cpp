/**
 * Clone a Linked list with next and random pointer
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* next, *random;
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
    node *temp = h;
    while(temp)
    {
        cout<<"Data = "<<temp->data<<", Random = "<<temp->random->data<<endl;
        temp=temp->next;
    }
    printf("\n");
}

node *clone(node *h)
{
    node *curr = h, *temp;

    //inserting copy of node after every node in list
    while(curr)
    {
        temp = curr->next;
        curr->next = newNode(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = h;

    //setting random pointer of the newly created copy nodes
    while(curr)
    {
        curr->next->random = curr->random->next;
        //skipping the original node and moving to copy node
        //the curr->next is checked as when curr->next becomes NULL
        //curr->next->next throws an error
        curr = curr->next?curr->next->next:curr->next;
    }

    node *original = h, *copy = h->next;

    //saving header of copy list
    temp = copy;

    //separating original and copy list
    while(original && copy)
    {
        original->next = original->next?original->next->next:original->next;
        copy->next = copy->next?copy->next->next:copy->next;
        original=original->next;
        copy=copy->next;
    }
    return temp;
}

int main()
{
    node *h = NULL;
    h = newNode(1);
    h->next = newNode(2);
    h->next->next = newNode(3);
    h->next->next->next = newNode(4);
    h->next->next->next->next = newNode(5);

    //1 point to 3
    h->random = h->next->next;

    //2 point to 1
    h->next->random = h;

    //3 and 4 points to 5
    h->next->next->random = h->next->next->next->next;
    h->next->next->next->random = h->next->next->next->next;

    //5 points to 2
    h->next->next->next->next->random = h->next;

    cout<<"Original List\n";
    print(h);

    node* clone_head = clone(h);

    cout<<"Clone List\n";
    print(clone_head);
}
