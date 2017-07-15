/*********************************************
*
*  Find vertical Sum of a binary tree
*
*/////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

typedef struct tree {
  int data;
  struct tree *left, *right;
} node;

node *create() {
  node* p;
  int n;
  cout<<"\nEnter data (Enter -1 if no child node) : ";
  cin>>n;
  if(n == -1) {
    return NULL;
  }
  p = (node*)malloc(sizeof(node));
  p->data = n;
  cout<<"\nEnter left child of "<<n;
  p->left = create();
  cout<<"\nEnter right child of "<<n;
  p->right = create();
  return p;
}

void inorder(node *root) {
	if(root) {
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
}

void verticalSumUtil(node *root, int hd, map<int, int> &Map) {
	if(root == NULL) return;

	verticalSumUtil(root->left, hd-1, Map);
	Map[hd] += root->data;
	verticalSumUtil(root->right, hd+1, Map);
}

void verticalSum(node* root) {
	map<int, int> Map;
	map<int, int> :: iterator itr;
	verticalSumUtil(root, 0, Map);

	for (itr = Map.begin(); itr != Map.end(); ++ itr)
	{
		cout<<itr->first<<":"<<itr->second<<endl;
	}
}

int main() {
    node * root;
    root = create();
    cout<<"\nInorder traversal of tree is ";
    inorder(root);
    cout<<"\nVertcal sum of tree is \n ";
    verticalSum(root);
	return 0;
}
