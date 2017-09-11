/*********************************************
*
*  Find maximum element from a min-heap
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int getMax(int heap[], int n) {
	//the largest value in min-heap will always appear after the parent of last value
	//so getting parent of last value in heap and checking for largest value from there
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
	int heap[] = {1,3,4,6,9,5,7};
	int n = sizeof(heap) / sizeof(heap[0]);
	printf("\nThe maximum value in min-heap is %d", getMax(heap, n));
}
