/**
 * Rearrange array in wave form
 */

#include <bits/stdc++.h>
using namespace std;

void wave(int arr[], int n)
{
    for(int i=1;i<n;i+=2)
    {
        if(arr[i-1] > arr[i])
            swap(arr[i-1], arr[i]);
        if(arr[i] < arr[i+1])
            swap(arr[i], arr[i+1]);
    }
}

int main()
{
    int arr[] = {10, 90, 49, 2, 1, 5, 23, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    wave(arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
