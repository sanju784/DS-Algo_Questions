/*********************************************
*
*  Find element in a Bitonic array
*
*  Bitonic array - an array with first k element in increasing and then decreasing order
*/////////////////////////////////////////////

#include <stdio.h>

int descendingBinarySearch(int arr[], int low, int high, int key) {
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid] == key)
			return mid;
		if(key<arr[mid])
			low = mid+1;
		else
			high= mid-1;
	}
	return -1;
}

int ascendingBinarySearch(int arr[], int low, int high, int key) {
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid] == key)
			return mid;
		if(key>arr[mid])
			low = mid+1;
		else
			high= mid-1;
	}
	return -1;
}

int getPoint(int arr[], int n) {
	int low=0, high = n-1, mid;
	while(low<=high){
		if(low==high) return low;
		if(high == low+1)
			return (arr[low] > arr[high]) ? low:high;
		mid=low+(high-low)/2;
		if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
			return mid;
		else if(arr[mid] > arr[mid-1] && arr[mid+1] > arr[mid])
			low = mid+1;
		else if(arr[mid] < arr[mid-1] && arr[mid+1]<arr[mid])
			high = mid-1;
	}
	return -1;
}

int search(int arr[], int n , int key) {
	int k = getPoint(arr, n);
	if(arr[k] == key)
		return k;
	else if(key > arr[k])
		return -1;
	int res = ascendingBinarySearch(arr, 0, k-1, key);
	if(res!=-1)
		return res;
	return descendingBinarySearch(arr, k+1, n-1, key);
}

void main(){
	int arr1[] = {-3, 9, 18, 20, 17, 5, 1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int key = 20;
    int res = search(arr1, n, key);
    if(res != -1)
    	printf("%d is at %d position", key, res+1);
}
