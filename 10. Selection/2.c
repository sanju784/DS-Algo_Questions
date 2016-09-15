/**
 * Find Smallest and largest in an array
 */

#include <stdio.h>
#include <limits.h>

void smallestLargest(int arr[], int n) {
	int i, s=INT_MAX, l=INT_MIN;
	for(i=0;i<n-1;i=i+2) {
		if(arr[i] < arr[i+1]) {
			if(arr[i] < s)
				s=arr[i];
			if(arr[i+1]>l)
				l=arr[i+1];
		} else {
			if(arr[i+1]<s)
				s=arr[i+1];
			if(arr[i]>l)
				l=arr[i];
		}
	}
	printf("Smallest = %d\nLargest = %d ", s, l);
}

void main() {
	int arr[] = {2,5,1,9,6,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	smallestLargest(arr, n);
}