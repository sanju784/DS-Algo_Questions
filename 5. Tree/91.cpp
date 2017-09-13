/**
 * Maximum path sum in a binary tree
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

int getMaxSumUtil(node *root, int &res)
{
    if(root == NULL)
        return 0;

    int l = getMaxSumUtil(root->left, res);
    int r = getMaxSumUtil(root->right, res);

    //getting max by the below 4 conditions
    //1. including only root
    //2. Including root and its left
    //3. Including root and its right
    //4. Including root and both of its child

    //here checking for the conditions 1-3
    int max_single = max(max(l,r) + root->data, root->data);

    //here checking for condition 4
    int max_top = max(max_single, l+r+root->data);

    res = max(res, max_top);

    return max_single;
}

int getMaxSum(node *root)
{
    int res = INT_MIN;

    getMaxSumUtil(root, res);

    return res;
}

int main()
{
    node *p = newNode(10);
    p->left = newNode(2);
    p->right = newNode(10);
    p->left->left = newNode(20);
    p->left->right = newNode(1);
    p->right->left = newNode(-5);
    p->right->right = newNode(-25);

    inorder(p);
    printf("\n");

    cout<<"Maximum Path sum is "<<getMaxSum(p);
}
