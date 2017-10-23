/**
 * Delete all half nodes from a tree
 *
 * Half Node - nodes with one child
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct tNode
{
    int data;
    struct tNode *left, *right;
}node;

node *newNode(int val) {
  node *newN = (node*)malloc(sizeof(node));
  newN->data = val;
  newN->left = NULL;
  newN->right = NULL;
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

//using post order traversal way
node* removeHalfNode(node* root)
{
    if(root== NULL)
        return NULL;

    root->left = removeHalfNode(root->left);
    root->right = removeHalfNode(root->right);

    if(root->left == NULL && root->right == NULL)
        return root;

    //if left of current node is NULL
    //then replacing it with its right
    if(root->left == NULL)
    {
        node* temp = root->right;
        free(root);
        return temp;
    }

    //if right of current node is null
    //then replacing it with its left
    if(root->right == NULL)
    {
        node *temp = root->left;
        free(root);
        return temp;
    }

    return root;
}

int main()
{
    node *p = newNode(4);
    p->left = newNode(2);
    p->right = newNode(6);
    //p->left->left = newNode(1);
    p->left->right = newNode(3);
    p->right->left = newNode(5);
    //p->right->right = newNode(7);

    inorder(p);
    printf("\n");

    node *root2 = removeHalfNode(p);
    inorder(p);
}
