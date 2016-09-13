/*********************************************
*
*  Print frequency of elements in an array
*
*/////////////////////////////////////////////

#include <stdio.h>

void printfrequency(int arr[], int n) {
	int i;
	for(i=0;i<n;i++)
		arr[i] = arr[i]-1;
	for(i=0;i<n;i++)
		arr[arr[i]%n] = arr[arr[i]%n] + n;
	for(i=0;i<n;i++)
		printf("%d -> %d\n", i+1, arr[i]/n);
}

void main() {
	int arr[] = {2, 3, 3, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printfrequency(arr,n);
}