/**
 * In sorted rotated array count total rotations
 */

#include <bits/stdc++.h>
using namespace std;

void getPair(int arr[], int n)
{
    int l = 0, r = n-1;
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
        {
            cout<<"Total rotation "<<(n-mid-1);
            return;
        }
        if(arr[mid] > arr[l])
            l = mid+1;
        else
            r = mid-1;
    }
}

int main()
{
    int arr[] = {8,9,1,2,3,4,5,6,7};
    int n = 9;
    getPair(arr, n);
}
