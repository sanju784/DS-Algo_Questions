/**
 * In sorted rotated array find pair with given sum
 */

#include <bits/stdc++.h>
using namespace std;

int getPair(int arr[], int n, int k)
{
    int l, r;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i] > arr[i+1])
        {
            l = (i+1)%n;
            r = i;
            break;
        }
    }

    bool flg = false;
    while(r != l)
    {
        if(arr[l] + arr[r] == k)
        {
            cout<<arr[l]<<" "<<arr[r]<<endl;
            flg = true;
        }
        else if(arr[l] + arr[r] < k)
            l = (l+1)%n; //if l becomes n-1 then then it will be changed to 0
        else
            r = (n+r-1)%n; //if r becomes 0 then then it will be changed to n-1
    }
    if(flg == false)
    printf("Pair with %d does not exist", k);
}

int main()
{
    int arr[] = {4,5,6,7,8,9,1,2,3};
    int n = 9;
    int k = 9;
    getPair(arr, n, k);
}

/**

In sorted array
int l=0, r=n-1
while(l != r)
{
if(arr[l] + arr[r] == k)
    cout<<arr[l]<<arr[r];
else if(arr[l] + arr[r] < k)
    l++;
else
    r--;
}

In unsorted array hashing is best way to use

*/
