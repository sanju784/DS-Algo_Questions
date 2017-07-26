/*********************************************
*
*  Find k-th max element from max heap
*
*/////////////////////////////////////////////

#include <stdio.h>

void maxHeapify(int h[], int i, int n) {
    int max = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l< n && h[l]>h[i])
         max = l;
    if(r< n && h[r]>h[max])
         max = r;
    if(max != i) {
        int temp = h[i];
        h[i] = h[max];
        h[max] = temp;
        maxHeapify(h,max,n);
    }
}

int getPos(int heap[], int k, int n) {
    int i = 1;
    while(i < k) {
        int temp = heap[0];
        heap[0] = heap[n-i];
        heap[n-i] = temp;
        maxHeapify(heap, 0, n-i);
        i++;
    }
    return heap[0];
}

void main() {
	int heap[] = {10,7,9,3,5,8,6};
	int n = sizeof(heap) / sizeof(heap[0]);
	printf("\nEnter position you want to get ");
	int k;
	scanf("%d", &k);
	if(k >0 && k <= n)
	    printf("\nThe element at position %d is %d", k, getPos(heap, k, n));
	else
        printf("\nEntered position not in range.");
}
