/**
 * Find node with the closest given key, in BST
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

void getClosestItr(node *p, int k)
{
    queue<node*> q;
    q.push(p);
    int min_diff = INT_MAX;
    node *temp, *res;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(abs(k - temp->data) < min_diff)
        {
            min_diff = k - temp->data;
            res = temp;
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    cout<<"Closest Node of "<<k<<" is "<<res->data;
}

//This solution uses property of BST as it searches left or right depending upon key value thus making (log n) as time complexity
void getClosestRecUtil(node* p, int k, int &min_diff, int &min_diff_key)
{
    if(p == NULL)
        return;

    //if k is in tree the this will be the result
    if(p->data == k)
    {
        min_diff_key = k;
        return;
    }

    //updating the result
    //if current node has less diff then before
    if(min_diff > abs(p->data - k))
    {
        min_diff = abs(p->data -k);
        min_diff_key = p->data;
    }

    //if k is less than the current node move it to left else right
    if(k < p->data)
        getClosestRecUtil(p->left, k, min_diff, min_diff_key);
    else
        getClosestRecUtil(p->right, k, min_diff, min_diff_key);
}

void getClosestRec(node *p, int k)
{
    //check for minimum difference till now
    int min_diff = INT_MAX;
    //check for the node which has the result i.e. node which has minimum absolute difference with k
    int min_diff_key = -1;

    getClosestRecUtil(p, k, min_diff, min_diff_key);

    cout<<"\nClosest Node of "<<k<<" is "<<min_diff_key;
}

int main()
{
    node *p = newNode(9);
    p->left = newNode(4);
    p->right = newNode(17);
    p->left->left = newNode(3);
    p->left->right = newNode(6);
    p->right->left = newNode(15);
    p->right->right = newNode(20);

    inorder(p);
    printf("\n");

    int k = 10;
    getClosestItr(p, k);
    getClosestRec(p, k);
}
