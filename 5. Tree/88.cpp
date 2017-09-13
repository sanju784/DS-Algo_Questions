/**
 * Connect nodes at same level
 *
 * Here without using any extra space
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

//The function to get the next of current node
node *getNext(node *p)
{
    node *temp = p->next;

    //run loop till last node of the same level and check for next
    while(temp != NULL)
    {
        if(temp->left != NULL)
            return temp->left;
        if(temp->right != NULL)
            return temp->right;
        temp = temp->next;
    }

    //if there is no next node of current node
    return NULL;
}

//to get next in iterative way
//we start from root of the tree set it's next then move down
void connect(node *p)
{
    if(p == NULL)
        return;

    //setting for root node
    p->next = NULL;

    while(p != NULL)
    {
        node *q = p;

        //moving level by level
        while(q != NULL)
        {
            if(q->left)
            {
                //if current node has right
                if(q->right)
                    q->left->next = q->right;
                else
                    q->left->next = getNext(q);
            }

            if(q->right)
                q->right->next = getNext(q);

            q = q->next;
        }

        //to start from the first node of the next level
        if(p->left)
            p = p->left;
        else if(p->right)
            p = p->right;
        else
            p = getNext(p);
    }
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
