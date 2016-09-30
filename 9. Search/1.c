/*********************************************
*
*  Check for duplicates in array
*
*/////////////////////////////////////////////

#include <stdio.h>

void printDuplicates(int arr[], int n) {
	int i;
	for(i=0;i<n;i++) {
		arr[arr[i]%n]+=n;
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]/n > 1)
			printf("%d ", i);
	}
}

void main() {
	int arr[] = {1,6,3,1,3,6,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("\nThe duplicates in array are ");
	printDuplicates(arr, n);
}