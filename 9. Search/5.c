/*********************************************
*
*  Find element that appear maximum number of times
*
*  Numbers are in range of 0 to n-1
*/////////////////////////////////////////////

#include <stdio.h>

void maxFrequency(int arr[], int n) {
	int i;
	for(i=0;i<n;i++)
		arr[arr[i]%n] += n;
	
	int max = 0;
	for(i=0;i<n;i++)
		if(arr[i]/n > max)
			max = i;
		
	printf("%d", max);
}

void main() {
	int arr[] = {1,6,3,1,3,6,6,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	//printf("%d ", maxFrequency(arr, n));
	printf("The elements repeating maximum time is ");
	maxFrequency(arr, n);
}
