/**
 * Array rotation
 * Using reversal Algorithm
 */
#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end)
{
    while(start<end)
    {
        swap(arr[start], arr[end-1]);
        start++;
        end--;
    }
}

void rotate(int arr[], int n, int d)
{
    reverse(arr, 0, d);
    reverse(arr, d+1, n);
    reverse(arr, 0, n);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7, k = 2;
    cout<<"Before rotate\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    rotate(arr,n,k);
    cout<<"\nAfter rotate\n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
