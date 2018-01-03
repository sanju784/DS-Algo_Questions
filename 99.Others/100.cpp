/**
 * Shuffle an array
 */
#include <bits/stdc++.h>
using namespace std;

void randomize(int arr[], int n)
{
    srand(time(NULL));
    for(int i=n-1;i>=0;i--)
    {
        int pos = rand()%(i+1);
        swap(arr[pos], arr[i]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    randomize (arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
