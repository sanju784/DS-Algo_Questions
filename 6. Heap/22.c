/*********************************************
*
*  Merge k sorted array
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

#define n 4

typedef struct MinHeapNode{
  int element;
  int i;
  int j;
}MinHeapNode;

void swap(MinHeapNode *x, MinHeapNode *y) {
  MinHeapNode temp = *x;
  *x = *y;
  *y = temp;
}

MinHeapNode *harr;
int heap_size;

void MinHeap(MinHeapNode a[], int size);

void MinHeapify(int);
int left(int i){ return 2*i+1; }
int right(int i){ return 2*i+2; }
MinHeapNode getMin() { return harr[0]; }

void replaceMin(MinHeapNode x) { harr[0] = x; MinHeapify(0); }

int *mergeKArray(int arr[][n], int k) {
    int *output = (int*)malloc(sizeof(int)*n*k);

    MinHeapNode *harr = (MinHeapNode*)malloc(sizeof(MinHeapNode)*k);

    for(int i=0; i<k; i++) {
        harr[i].element = arr[i][0];
        harr[i].i = i;
        harr[i].j = 1;
    }

    MinHeap(harr,k);
    for(int count = 0;count < n*k; count++) {
        MinHeapNode root = getMin();
        output[count] = root.element;
        if(root.j<n) {
            root.element = arr[root.i][root.j];
            root.j += 1;
        } else
          root.element = INT_MAX;
        replaceMin(root);
    }
    return output;
}

void MinHeap(MinHeapNode a[], int size) {
    heap_size = size;
    harr = a;
    int i = (heap_size - 1)/2;
    while(i >= 0){
        MinHeapify(i);
        i--;
    }
}

void MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int min = i;
    if(l < heap_size && harr[l].element < harr[i].element)
        min = l;
    if(r < heap_size && harr[r].element < harr[min].element)
        min = r;
    if(min != i) {
        swap(&harr[i], &harr[min]);
        MinHeapify(min);
    }
}

void printArray(int arr[], int size) {
  for(int i =0;i<size;i++)
    printf("%d  ",arr[i]);
}

void main() {
  int arr[][n] = {{2, 6, 12, 34},
                   {1,9,20,1000},
                   {23,34,90,2000}
                 };
  int k = sizeof(arr)/sizeof(arr[0]);
  int *resArr = mergeKArray(arr, k);
  printf("\nResult array is ");
  printArray(resArr, n*k);
}
