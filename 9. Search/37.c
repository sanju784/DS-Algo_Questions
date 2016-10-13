/*********************************************
*
*  Find index at which an increasing array become decreasing
*
*/////////////////////////////////////////////

#include <stdio.h>

int search(int arr[], int start, int end){
	int mid;
	while(start <= end){
		if(start == end) return start;
		else if(start == end-1) return start;
		else {
			mid = start + (end-start)/2;
			if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
				return mid;
			else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1])
				start = mid+1;
			else if(arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1])
				end = mid-1;
		}
	}
}

void main() {
	int arr[] = {1,3,4,7,8,9,7,5,4,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Starting index at %d", search(arr, 0, n-1));
}