/*********************************************
*
*  Shuffle array a1a2a3a4b1b2b3b4 to a1b1a2b2a3b3a4b4
*
*/////////////////////////////////////////////

#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

void interChange(int arr[], int len) {
	int n = len/2,i,j;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			swap(&arr[n-i+2*j], &arr[n-i+2*j+1]);
		}
	}
}

void main() {
	int arr[] = {1,2,3,4,5,6,7,8};
	int i;
	interChange(arr, 8);
	for(i=0;i<8;i++)
		printf("%d ", arr[i]);
}