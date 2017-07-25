/*********************************************
*
*  Find k-th smalledt element in a binary heap
*
*/////////////////////////////////////////////

#include <stdio.h>

void minHeapify(int h[], int i, int n) {
    int min = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l< n && h[l]<h[i])
         min = l;
    if(r< n && h[r]<h[min])
         min = r;
    if(min != i) {
        int temp = h[i];
        h[i] = h[min];
        h[min] = temp;
        minHeapify(h,min,n);
    }
}

int getPos(int heap[], int k, int n) {
    int i = 1;
    while(i < k) {
        int temp = heap[0];
        heap[0] = heap[n-i];
        heap[n-i] = temp;
        minHeapify(heap, 0, n-i);
        i++;
    }
    return heap[0];
}

void main() {
	int heap[] = {2,4,5,9,7,6,8};
	int n = sizeof(heap) / sizeof(heap[0]);
	printf("\nEnter position you want to get ");
	int k;
	scanf("%d", &k);
	if(k >0 && k <= n)
	    printf("\nThe element at position %d is %d", k, getPos(heap, k, n));
	else
        printf("\nEntered position not in range.");
}
