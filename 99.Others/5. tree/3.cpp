/**
 * Print PostOrder from inorder and preorder
 */
#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int x, int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == x)
            return i;
    }
    return -1;
}

void printPost(int in[], int pre[], int n)
{
    int root = search(in, pre[0], n);

    if(root != 0)
        printPost(in, pre+1, root);

    if(root != n-1)
        printPost(in+root+1, pre+root+1, n-root-1);
    cout<<pre[0]<<" ";
}

int main()
{
    int in[] = {4,2,5,1,6,3,7};
    int pre[] = {1,2,4,5,3,6,7};
    int n = sizeof(pre)/sizeof(pre[0]);
    printPost(in, pre, n);
}
