/*********************************************
*
*  Delete i-th index element from a min-heap
*
*/////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

void heapify(int h[], int i, int n)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int min = i;
    if(l < n && h[l] < h[min])
        min = l;
    if(r < n && h[r] < h[min])
        min = r;

    if(min != i)
    {
        swap(h[i], h[min]);
        heapify(h, min, n);
    }
}

void del(int h[], int *n, int i)
{
    h[i] = h[*n-1];
    (*n)--;
    heapify(h, i, *n);
}

int main()
{
    int heap[] = {1,3,4,6,9,5,7};
    int n = sizeof(heap)/sizeof(heap[0]);
    printf("\nEnter position you want to delete ");
    int pos;
    scanf("%d", &pos);
    del(heap, &n, pos);
    printf("\nNew heap ");
    for(int i=0;i<n;i++)
        cout<<heap[i]<<" ";
}
