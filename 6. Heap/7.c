/*********************************************
*
*  Find maximum element from a min-heap
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int getMax(int heap[], int n) {
	//parent of last value
	int p = ((n-1)-1)/2;
	int i;
	int max = INT_MIN;
	for(i = p+1; i<n; i++) {
		if(heap[i] > max)
			max = heap[i];
	}
	return max;
}

void main() {
	int heap[] = {1, 2, 5, 3, 4, 6, 7};
	int n = sizeof(heap) / sizeof(heap[0]);
	printf("\nThe maximum value in min-heap is %d", getMax(heap, n));
}