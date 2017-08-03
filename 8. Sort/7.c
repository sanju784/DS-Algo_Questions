/*********************************************
*
*  Sort array of size n with elements in range 1~n^3
*
*/////////////////////////////////////////////

#include <stdio.h>

void countSort(int a[], int n, int exp) {
	int output[n];
	int i, count[n];
	for(i=0;i<n;i++)
		count[i] = 0;
	for(i=0;i<n;i++)
		count[(a[i]/exp)%n]++;
	for(i=1;i<n;i++)
		count[i] = count[i]+count[i-1];
	for(i=n-1;i>=0;i--) {
		output[count[(a[i]/exp)%n]-1] = a[i];
		count[(a[i]/exp)%n]--;
	}
	for(i=0;i<n;i++)
		a[i] = output[i];
}

void sort(int a[], int n) {

	//first exp (n^0 = 1)
	countSort(a, n, 1);

	//second exp (n^1 = n)
	countSort(a, n, n);

	//third exp (n^2 = n)
	countSort(a, n, n*n);
}

void main() {
	int arr[] = {340, 120, 45, 32, 303, 1, 48};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i;
	// here subtrcting 1 from the number so as to make the numbers in the range of 0 to n^3-1
	// this is done so as make all numbers 3 digit in the base of n
	// so to sort all 3 digit number we need to runs of countsort 3 times
	for(i=0;i<n;i++)
		arr[i] = arr[i]-1;
	sort(arr, n);
	for(i=0;i<n;i++)
		arr[i] = arr[i]+1;
	printf("%d\nThe sorted array is ");
	for(i=0;i<n;i++)
		printf("%d ", arr[i]);
}