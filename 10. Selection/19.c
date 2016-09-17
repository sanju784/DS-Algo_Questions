/**
 * Find k nearest neighbour to the median of n numbers
 */

#include <stdio.h>

void printKNearest(int arr[], int n, int k) {
	int l = n/2-1;
	int r = n/2+1;
	int count = 0;
	// getting median of array
	int m = arr[n/2];

	while(l>0 && r<n && count<k)
	{
		if(m-arr[l] < arr[r] - m)
			printf("%d ", arr[l--]);
		else
			printf("%d ", arr[r++]);
		count++;
	}

// If no elements on right side
	// print left elements
	while(count<k && l>=0)
		printf("%d ", arr[l--]), count++;

//If no element on left side
	//printing right elements
	while(count <k && r < n)
		printf("%d ", arr[r++]), count++;
}

void main() {
	int arr[] = {1,3,5,8,9,10,13,15,19};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k =4;
	printKNearest(arr, n, k);
}