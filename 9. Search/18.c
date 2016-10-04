/*********************************************
*
*  Find number occuring odd number of times
*
*/////////////////////////////////////////////

#include <stdio.h>

int getOddOccurance(int arr[], int n) {
	int i, x=arr[0];
	for(i=1;i<n;i++) {
		x^=arr[i];
	}
	return x;
}

void main() {
	int arr[] = {1,6,3,1,3,6,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("\nThe odd in array is %d", getOddOccurance(arr, n));
}