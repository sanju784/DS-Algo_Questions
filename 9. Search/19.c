/*********************************************
*
*  Find two repeating elements in an array
*
*/////////////////////////////////////////////

#include <stdio.h>

void printRepeat(int arr[], int n) {
	int count[n-2], i;
	for(i=0;i<n-2;i++)
		count[i]=0;
	for(i=0;i<n;i++)
	    count[arr[i]%n]++;
	for(i=0;i<n-2;i++){
		if(count[i]>1)
			printf("%d ", i);
	}
}

void main() {
	int arr[] = {4, 2, 4, 5, 2, 3, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("\nThe repeat in array are ");
	printRepeat(arr, n);
}