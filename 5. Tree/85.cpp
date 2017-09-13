/**
 * Delete all leaf node from tree
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

//here using preorder way of traversal
node *removeLeaf(node *root)
{
    if(root == NULL)
        return NULL;

    //deleting leaf here and returning NULL to its parent
    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    root->left = removeLeaf(root->left);
    root->right = removeLeaf(root->right);

    return root;
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

    node *root2 = removeLeaf(p);
    inorder(root2);
}
