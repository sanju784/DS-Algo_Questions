/**
 * Given a low and high value
 *
 * Rearrange array that all numbers less than low appear before
 * all numbers greater than high appear after high
 * numbers between low and high must appear between them
 */

#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n, int low, int high)
{
    int start = 0, end = n-1;
    for(int i = 0; i<=end;)
    {
        //if current element is smaller than range
        //put it on next available smaller position
        if(arr[i] < low)
            swap(arr[i++], arr[start++]);
        //if current number is greater than range
        //put it on next available higher position
        else if(arr[i] > high)
            swap(arr[i], arr[end--]);
        else
            i++;
    }
}

int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 15, 87, 98, 3, 1, 32,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 10, high = 20;
    rearrange(arr, n, low, high);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
