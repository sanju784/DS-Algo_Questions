/**
 * Find maximum length of a bitonic subarray in an array
 */

#include <bits/stdc++.h>
using namespace std;

void bitonic(int arr[], int n)
{
    int inc[n]; //length of increasing order of array till current index
    int dec[n]; //length of decreasing order of array till current index
    inc[0] = 1; // first value will have one increasing length
    dec[n-1] = 1; //last value of one decreasing length
    //calculating increasing order length of all array index
    for(int i=1;i<n;i++)
    {
        if(arr[i] >= arr[i-1])
        {
            inc[i] = inc[i-1] + 1;
        }
        else
        {
            inc[i] = 1;
        }
    }
    //calculating decreasing order length of all array index
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i] >= arr[i+1])
        {
            dec[i] = dec[i+1] + 1;
        }
        else
        {
            dec[i] = 1;
        }
    }

    //calculating maximum of decreasing and increasing order length from current position
    int max = inc[0] + dec[0] - 1;
    for(int i=1;i<n;i++)
    {
        if(inc[i] + dec[i] -1 > max)
            max = inc[i] + dec[i] -1;
    }
    cout<<max;
}

int main()
{
    int arr[] = {12, 4, 78, 90, 45, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    bitonic(arr, n);
}
