/*********************************************
*
*  Find Shortest Path bewteen 2 nodes in a BST
*
*/////////////////////////////////////////////

#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

typedef struct treeNode{
  int data;
  struct treeNode *left;
  struct treeNode *right;
} node;

node *newNode(int n) {
  node *p = (node*)malloc(sizeof(node));
  p->data = n;
  p->left = NULL;
  p->right = NULL;
  return p;
}

/**
     4
    / \
  2     6
 / \   / \
1   3 5   7

*/
node *createBST() {
  node *p = newNode(4);
  p->left = newNode(2);
  p->right = newNode(6);
  p->left->left = newNode(1);
  p->left->right = newNode(3);
  p->right->left = newNode(5);
  p->right->right = newNode(7);
  return p;
}

node* findLCA(node* root, int a, int b) {
  while(root != NULL) {
    if(a <= root->data && b >= root->data) {
      return root;
    } else if (root->data > a && root->data > b) {
      root = root->left;
    } else {
      root = root->right;
    }
  }
}

void printShortestPath(node *top, int n1, int n2) {
  node *temp1 = top;
  node *temp2 = top;
  stack<int> s;
  while(temp1->data != n1) {
      if(n1 < temp1->data) {
        temp1 = temp1->left;
      } else {
        temp1 = temp1->right;
      }
      s.push(temp1->data);
    }

    while(!s.empty()) {
      cout<<" "<<s.top();
      s.pop();
    }
    cout<<" "<<top->data;
    while(temp2->data != n2) {
      if(n2 < temp2->data) {
        temp2 = temp2->left;
      } else {
        temp2 = temp2->right;
      }
      cout<<" "<<temp2->data;
    }
}

int main() {
  node *root = createBST();
  int n1, n2;
  cout<<"Enter numbers whose shortest path needed ";
  cin>>n1>>n2;
  if(n1 > n2){
    int n = n1;
    n1 = n2;
    n2 = n;
  }
  node *res = findLCA(root, n1, n2);
  if (res) {
    printShortestPath(res, n1, n2);
  } else {
    cout<<"\nNo common path found";
  }
  return 0;
}