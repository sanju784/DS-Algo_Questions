/**
 * Reverse Level order Traversal
 */
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

node *newNode(int n)
{
    node* newN = (node*)malloc(sizeof(node));
    newN->data = n;
    newN->left = NULL;
    newN->right = NULL;
    return newN;
}

void revLevel(node *root)
{
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        s.push(temp);
        q.pop();
        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
    }
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
    }
}

int main()
{
    node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    revLevel(root);
}
