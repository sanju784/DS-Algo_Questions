/**
 * Rearrange positive and negative number in an array in alternate way
 */

#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
    //moving all negative numbers at start of array
    //and all negative numbers at end using 0 as pivot
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] < 0)
            swap(arr[index++], arr[i]);
    }

    //saving staring index of the positive and negative numbers
    int pos_index = index, neg_index = 0;

    //swapping alternate negative numbers with next positive element
    while(pos_index < n && neg_index < n && arr[neg_index] < 0)
    {
        swap(arr[neg_index], arr[pos_index]);
        pos_index += 1;
        neg_index += 2;
    }
}

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
