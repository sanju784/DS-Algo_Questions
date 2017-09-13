/**
 * Connect nodes at same level
 *
 * Here using Level order Traversal
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct tNode
{
    int data;
    struct tNode *left, *right, *next;
}node;

node *newNode(int val) {
  node *newN = (node*)malloc(sizeof(node));
  newN->data = val;
  newN->left = NULL;
  newN->right = NULL;
  newN->next = NULL;
  return newN;
}

void inorder(node *p)
{
    if(p)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

//using Level Order Traversal
void connectAdjacent(node *root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            if(!q.empty())
            q.push(NULL);
        }
        else{
          temp->next = q.front();
          if(temp->left)
            q.push(temp->left);
          if(temp->right)
            q.push(temp->right);
        }
    }
}

//traversing nodes in pre order way
void connectRecur(node *p)
{
    if(p == NULL)
        return;

    //The next of left pointer will always be its right child
    if(p->left)
        p->left->next = p->right;

    //The next of right child will always be left child of its parent next
    if(p->right)
        p->right->next = (p->next)?p->next->left:NULL;

    connectRecur(p->left);
    connectRecur(p->right);
}

//using recursive way for Complete binary tree
void connect(node *p)
{
    p->next = NULL;

    connectRecur(p);
}

int main()
{
    node *p = newNode(4);
    p->left = newNode(2);
    p->right = newNode(6);
    p->left->left = newNode(1);
    p->left->right = newNode(3);
    p->right->left = newNode(5);
    p->right->right = newNode(7);

    inorder(p);
    printf("\n");

    connectAdjacent(p);
    node *temp = p->left->left;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
