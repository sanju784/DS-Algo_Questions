/**
 * In BST remove nodes outside of range
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

//removing nodes out of range in postorder traversal way
//
node *pruneTree(node *root, int min, int max)
{
    if(root == NULL)
        return NULL;

    //first checking the left and right subtree as in postorder way
    root->left = pruneTree(root->left, min, max);
    root->right = pruneTree(root->right, min, max);

    //if current data is less than min
    //then replacing it with its right child
    if(root->data < min)
    {
        node *rChild = root->right;
        free(root);
        return rChild;
    }

    //if current data is greater than max range
    //the replacing it with its right child
    if(root->data > max)
    {
        node *lChild = root->left;
        free(root);
        return lChild;
    }

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

    int min=2, max=5;
    node *root1 = pruneTree(p, min, max);
    inorder(root1);
}
