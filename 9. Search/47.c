/*********************************************
*
*  Find index of last occurance of a number in array with duplicate values
*
*/////////////////////////////////////////////

#include <stdio.h>

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

void main() {
  int arr[] = {1, 2, 2, 3, 3, 3, 3};
  int x =  3;
  int n = sizeof(arr)/sizeof(arr[0]);
  printf(" %d occurs last at %d ", x, last(arr, 0, n-1, x, n));
}