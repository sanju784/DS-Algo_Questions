/*********************************************
*
*  Find number that appeared maximum number of times
*
*/////////////////////////////////////////////

//The elements of array must be in the range of n

#include <stdio.h>

int getMaxRepeat(int arr[], int n) {
	int i;
	for(i=0;i<n;i++) {
		arr[arr[i]%n] += n;
	}
	int max = arr[0], res = 0;
	for(i=1;i<n;i++) {
		if(arr[i] > max) {
			max = arr[i];
			res=i;
		}
	}
	return res;
}

void main() {
	int arr[] = {2,3,3,5,3,4,1,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("The element that appear maximum %d", getMaxRepeat(arr, n));
}