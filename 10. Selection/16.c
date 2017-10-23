/**
 * Find k smallest elements in sorted order
 */

#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int a[], int n, int i) {
	int l = 2*i+1;
	int r = 2*i+2;
	int min=i;
	if(l<n && a[l] < a[min])
		min = l;
	if(r<n && a[r] < a[min])
		min = r;
	if(min!=i){
		swap(&a[i], &a[min]);
		heapify(a, n, min);
	}
}

int getMin(int a[], int n) {
	int res = a[0];
	a[0] = a[n];
	a[n] = res;
	heapify(a, n, 0);
	return res;
}

void main() {
	int a[] = {9,4,6,5,7,3,8,2,1};
	int n = sizeof(a)/sizeof(a[0]);
	int k = 4, i;
	for(i=(n-1)/2;i>=0;i--)
	    heapify(a, n, i);
	for(i=0; i<k;i++)
		printf("%d ", getMin(a, n-k-1));
}
