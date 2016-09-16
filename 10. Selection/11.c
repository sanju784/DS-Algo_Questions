/**
 * Find k'th smallest element
 */

#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *a, int start, int end) {
	int pivot = a[end];
	int pi = start;
	int i;
	for(i=start;i<end;i++) {
		if(a[i] <= pivot) {
			swap(&a[i], &a[pi]);
			pi++;
		}
	}
	swap(&a[pi], &a[end]);
	return pi;
}

void kSmallest(int arr[], int low, int high, int k) {
	int pi = partition(arr, low, high);
	if(pi==k) {
		printf("%d ", arr[k]);
	}
	else if(k < pi)
		kSmallest(arr, low, pi-1,k);
	else
		kSmallest(arr, pi+1, high, k);
}

void main() {
	int arr[] = {1,9,6,4,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k=3;
	if(n>k)
	kSmallest(arr, 0, n-1, k-1);
}