/**
 * In Sorted Array check if A[i]=i
 */
#include <stdio.h>

int searchIndex(int arr[], int start, int end)
{
	int mid = (end - start) / 2;
	if(mid == arr[mid])
		return mid + 1;
	else if(mid < arr[mid])
		searchIndex(arr, start, mid);
	else
		searchIndex(arr, mid, end);
}

void main()
{
	int arr[] = {-1,1,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("At position %d the index and element are same", searchIndex(arr, 0, n-1));
}