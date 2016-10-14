/*********************************************
*
*  Find element in a rotated array
*
*/////////////////////////////////////////////

#include <stdio.h>

int findPivot(int arr[], int low, int high) {
	if(high<low) return -1;
	if(low==high) return low;

	int mid = (low + high) / 2;
	if(mid < high && arr[mid] > arr[mid+1])
		return mid;
	if(mid > low && arr[mid] < arr[mid-1])
		return mid-1;
	if(arr[low] >= arr[mid])
		findPivot(arr, low, mid-1);
	else
		findPivot(arr, mid+1, high);
}

int binarySearch(int arr[], int low, int high, int key) {
	if(high < low) return -1;
	int mid=(low+high)/2;
	if(key == arr[mid])
		return mid;
	if(key < arr[mid])
		binarySearch(arr, low, mid-1, key);
	else
		binarySearch(arr, mid+1, high, key);
}

int search(int arr[], int n, int key) {
	int pivot = findPivot(arr, 0, n-1);
	if(pivot == -1)
		binarySearch(arr, 0, n-1, key);
	if(arr[pivot] == key)
		return pivot;
	if(arr[0] <= key)
		return binarySearch(arr, 0, pivot-1, key);
	else
		return binarySearch(arr, pivot+1, n-1, key);
}

void main() {
   int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int n = sizeof(arr)/sizeof(arr[0]);
   int key = 3;
   printf("%d is at %d position", key, search(arr, n , key));
}