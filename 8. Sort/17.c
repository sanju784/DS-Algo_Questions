/*********************************************
*
*  Sort an array of 0's 1's and 2's using quicksort
*
*/////////////////////////////////////////////

#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int start, int end) {
	int pivot = a[end], i, pi=start;
	for(i=start;i<end;i++) {
		if(a[i] <= pivot){
			swap(&a[i], &a[pi]);
			pi++;
		}
	}
	swap(&a[pi], &a[end]);
	return pi;
}

void quick(int a[], int start, int end) {
	if(start < end) {
		int pi = partition(a, start, end);
		quick(a, start, pi-1);
		quick(a, pi+1, end);
	}
}
void main() {
	int a[] = {0,1,1,0,1,2,1,2,0,0,0,1};
	int n = sizeof(a)/sizeof(a[0]);
	int i;
	quick(a, 0, n-1);
	
	for(i=0;i<n;i++)
		printf("%d ", a[i]);
}