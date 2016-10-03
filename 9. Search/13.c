/*********************************************
*
*  Find missing number in an array
*
*/////////////////////////////////////////////

//it can also be done by sum of AP n+1)*(n+2)/2
#include <stdio.h>

int findMissing(int arr[], int n) {
	int i, x=arr[0], y=1;
	for(i=1;i<n;i++) {
		x ^= arr[i];
		y ^= (i+1);
	}
	y^=(n+1);
	return x^y;
}

void main() {
	int arr[] = {1,2,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("\nThe missing in array is %d ", findMissing(arr, n));
}