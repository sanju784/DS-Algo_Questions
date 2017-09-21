/**
 * Rearrange array that all negative numbers appear at end in order
 */

#include <bits/stdc++.h>
using namespace std;

//This is using insertion sort method to put element at begin
//this will maintain the order of the array
void rearrange(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] < 0)
            continue;
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] < 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
