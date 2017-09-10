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

node* getLCA(node* root, int a, int b) {
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

void printShortestPath(node *lca, int n1, int n2) {
  node *temp = lca;
  if(n2 < n1)
	  swap(n1, n2);
  deque<int> dq;
  dq.push_front(temp->data);
    while(temp->data != n1) {
      temp = temp->left;
      dq.push_front(temp->data);
    }
	temp = lca;
    while(temp->data != n2) {
        temp = temp->right;
		dq.push_back(temp->data);
    }
	
	while(!dq.empty())
	{
		cout<<dq.front()<<" ";
		dq.pop_front();
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
  //getting LCA as path passes through it
  node *res = getLCA(root, n1, n2);
  if (res) {
    printShortestPath(res, n1, n2);
  } else {
    cout<<"\nNo common path found";
  }
  return 0;
}
