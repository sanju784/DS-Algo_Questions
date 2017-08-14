/*********************************************
*
*  Arrange an array in Saw Tooth Wave form (A<B>C<D>E<F)
*
*/////////////////////////////////////////////

#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void main(){
	int arr[] = {1,0,4,9,13,10,8,12,54,14};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i;
	for(i=1;i<n;i+=2) {
		if(arr[i-1] > arr[i])
			swap(&arr[i-1], &arr[i]);
		if(arr[i]<arr[i+1])
			swap(&arr[i], &arr[i+1]);
	}
	for(i=0;i<n;i++)
		printf("%d ", arr[i]);
}