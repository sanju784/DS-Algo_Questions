/*********************************************
*
*  Sort array of size n with elements in range 1~n^2
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
}

void main() {
	int arr[] = {40, 12, 45, 32, 33, 1, 48};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i;
	// here subtrcting 1 from the number so as to make the numbers in the range of 0 to n^2-1
	// this is done so as make all numbers 2 digit in the base of n
	// so to sort all 2 digit number we need to runs of countsort 2 times only
	// for eg. if n=8 n^2= 64 in base 8, 64 will be represented by 100
	// which is of 3 digit and 63 will be 77 which of 2 digit
	// Note : All numbers must be greater than 0
	for(i=0;i<n;i++)
		arr[i] = arr[i]-1;
	sort(arr, n);
	for(i=0;i<n;i++)
		arr[i] = arr[i]+1;
	printf("%d\nThe sorted array is ");
	for(i=0;i<n;i++)
		printf("%d ", arr[i]);
}