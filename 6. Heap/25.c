/*********************************************
*
*  Find largest n pair (A[i], B[i]) from 2 arrays A and B
*
*/////////////////////////////////////////////

#include <stdio.h>

void heapify(int h[], int n, int i) {
	int max = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<n && h[l]>h[max])
		max=l;
	if(r<n && h[r]>h[max])
		max=r;
	if(max!=i) {
		int temp = h[i];
		h[i] = h[max];
		h[max] = temp;
		heapify(h, n, max);
	}
}

void main() {
	int heap[] = {1,2,3,4,5,6,7};
	int n = sizeof(heap)/sizeof(heap[0]);
	int i;
	for(i = (n-1)/2; i>=0;i--)
		heapify(heap, n, i);
	
	int heap2[] = {8,9,10};
	int n2 = sizeof(heap2)/sizeof(heap2[0]);
	for(i = (n2-1)/2; i>=0;i--)
		heapify(heap, n2, i);
}