/*********************************************
*
*  Find element that are repeated twice
*
*/////////////////////////////////////////////

#include <stdio.h>

int twiceRepeat(int arr[], int size, int n) {
	int i, xor=arr[0];
	for(i=1;i<size;i++)
		xor ^= arr[i];
	for(i=1;i<=n;i++)
		xor ^= i;

	return xor;
}

void main() {
	int arr[] = {2,1,2,3,1,3,2,1};
	int n = 3;
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("\nThe two repeat in array is %d", twiceRepeat(arr, size, n));
}