/**
 * Array rotation
 */

#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n, int k)
{
    int temp;
    for(int i=0;i<k;i++)
    {
        temp = arr[0];
        for(int j=0;j<n-1;j++)
        {
            arr[j] = arr[j+1];
        }
        arr[n-1] = temp;
    }
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
