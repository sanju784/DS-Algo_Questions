/*********************************************
*
*  Check if an array is pair wise sorted
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>

bool pairSort(int arr[], int n) {
	int i;
	for(i=0;i<n-1;i=i+2){
		if(arr[i]>arr[i+1])
			return false;
	}
	return true;
}

void main() {
	int arr[] = {1,2,3,4,5,6,7,8};
	int n = 8;
	if(pairSort(arr, n))
		printf("Array is pair wise sorted");
	else
		printf("Array not pair wise sorted");
}