/**
 * Find second largest in an array
 */

#include <stdio.h>
#include <limits.h>

void smallestLargest(int arr[], int n) {
	int l = INT_MIN, sl = INT_MIN, i;
	for(i=0;i<n;i++){
		if(arr[i] > l){
			sl=l;
			l=arr[i];
		} else if(arr[i] >sl && arr[i] != l)
		    sl=arr[i];
	}
	printf("Second Largest = %d ", sl);
}

void main() {
	int arr[] = {2,5,1,9,6,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	smallestLargest(arr, n);
}