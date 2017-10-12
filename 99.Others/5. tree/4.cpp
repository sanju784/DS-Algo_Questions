/**
 * Diagonal Traversal of binary tree
 *
 * compile by g++ -std=c++0x 4.cpp
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

void inorder(node *p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}

void diagonalPrintUtil(node *root, int d, map<int, vector<int> > &diagPrint)
{
    if(!root)
        return;
    diagPrint[d].push_back(root->data);
    diagonalPrintUtil(root->left, d+1, diagPrint);
    diagonalPrintUtil(root->right, d, diagPrint);
}

void diagonalPrint(node *root)
{
    map<int,vector<int> > diagPrint;
    diagonalPrintUtil(root, 0, diagPrint);

    for(auto it = diagPrint.begin(); it != diagPrint.end(); it++)
    {
        for(auto itr = it->second.begin(); itr != it->second.end(); itr++)
            cout<<*itr<<" ";
        cout<<endl;
    }
}

int main()
{
    node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    diagonalPrint(root);
}
