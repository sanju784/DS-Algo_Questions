/*********************************************
*
*  Find element that appear maximum number of times
*
*/////////////////////////////////////////////

#include <stdio.h>

void maxFrequency(int arr[], int n) {
	int i;
	for(i=0;i<n;i++) {
		arr[arr[i]%n]+=n;
	}
	/**
	int max = arr[0], result = 0;
	for(i=1;i<n;i++)
	{
		if(arr[i] > max){
			max = arr[i];
			result = i;
		}
	}
	return result;
	*/
	int max = 0;
	for(i=0;i<n;i++){
		arr[i] = arr[i]/n;
		if(arr[i] > max)
			max=arr[i];
	}
	for(i=0;i<n;i++)
		if(arr[i] == max)
		printf("%d ", i);
}

void main() {
	int arr[] = {1,6,3,1,3,6,6,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	//printf("%d ", maxFrequency(arr, n));
	printf("The elements repeating maximum time is ");
	maxFrequency(arr, n);
}