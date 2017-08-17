/*********************************************
*
*  Find number of occurance of a number in array with duplicate values
*
*/////////////////////////////////////////////

#include <stdio.h>

int first(int arr[], int low, int high, int x) {
	if(high >= low) {
		int mid = (low+high)/2;
		if((mid==0 || arr[mid-1]<x)  && arr[mid] == x)
			return mid;
		else if(arr[mid] < x)
			return first(arr, mid+1, high, x);
		else
			return first(arr, low, mid-1, x);
	}
	return -1;
}

int last(int arr[], int low, int high, int x, int n) {
	if(high >= low){
		int mid = (low+high)/2;
		if((mid == n-1 || x < arr[mid+1]) && arr[mid]==x)
			return mid;
		else if (x < arr[mid])
			return last(arr, low, mid-1, x, n);
		else
			return last(arr, mid+1, high, x, n);
	}
	return -1;
}

int count(int arr[], int x, int n) {
	int i,j;
	i = first(arr, 0, n-1, x);
	if(i==-1)
		return -1;
	j = last(arr, i, n-1, x, n);
	return j-i+1;
}

void main() {
  int arr[] = {1, 2, 2, 3, 3, 3, 3};
  int x =  3;
  int n = sizeof(arr)/sizeof(arr[0]);
  int c = count(arr, x, n);
  printf(" %d occurs %d times ", x, c);
}