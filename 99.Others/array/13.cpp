/**
 * Rearrange a sorted array in maximum minimum form
 *
 * I/P - 1, 2, 3, 4, 5, 6, 7
 * O/P - 7, 1, 6, 2, 5, 3, 4
 */

#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
    int end = n-1, start = 0;
    int temp[n];
    int i=0;
    while(start <= end)
    {
        if(i%2 == 0)
            temp[i] = arr[end--];
        else
            temp[i] = arr[start++];

        i++;
    }

    for(int i=0;i<n;i++)
        arr[i] = temp[i];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
