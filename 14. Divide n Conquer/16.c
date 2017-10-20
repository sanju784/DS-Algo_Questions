/**
 * Get higest of duplicate in array
 */
#include <stdio.h>

int getHighIndex(int arr[], int n)
{
	int i;
	for(i=n-1;i>0;i--)
		if(arr[i] == arr[i-1])
			return i+1;
	return -1;
}

void main()
{
	int arr[] = {1,1,3,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int res = getHighIndex(arr, n);
	if(res == -1)
		printf("No duplicates");
	else
	    printf("Highest index at %d", res);
}