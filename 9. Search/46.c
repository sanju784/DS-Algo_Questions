/*********************************************
*
*  Find index of first occurance of a number in array with duplicate values
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

void main() {
  int arr[] = {1, 2, 2, 3, 3, 3, 3};
  int x =  3;
  int n = sizeof(arr)/sizeof(arr[0]);
  printf(" %d occurs first at %d ", x, first(arr, 0, n-1, x));
}