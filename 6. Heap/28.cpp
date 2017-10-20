/**
 * Maximum sliding window in an array
 */
#include <bits/stdc++.h>
using namespace std;

void heapify(int h[], int i, int n)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int min = i;
    if(l < n && h[l] > h[min])
        min = l;
    if(r < n && h[r] > h[min])
        min = r;

    if(min != i)
    {
        swap(h[i], h[min]);
        heapify(h, min, n);
    }
}

void maxim(int arr[], int n, int w)
{
    int h[w];
    for(int i=0;i<n-w+1;i++)
    {
      int k=0;
      for(int j=i;j<(i+w);j++)
      {
        h[k++] = arr[j];
      }
      for(int l=(w-1)/2;l>=0;l--)
        heapify(h,l,w);
     cout<<h[0]<<" ";
    }
}

int main()
{
    int arr[] = {1,3,5,9,0,2,6,7,4,8,10,11};

    int k = sizeof(arr)/sizeof(arr[0]);
    int w = 3;
    maxim(arr, k, w);
}
