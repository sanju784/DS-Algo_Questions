/*********************************************
*
*  Sort an array of 0's 1's and 2's
*
* Here using count Sort technique
*/////////////////////////////////////////////

#include <stdio.h>

void main() {
	int arr[] = {0,1,1,0,1,2,1,2,0,0,0,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int count[] = {0,0,0};
	int i;
	for(i=0;i<n;i++) {
		count[arr[i]]++;
	}
	int j=0;
	for(i=0;i<3;i++) {
		while(count[i]-- > 0)
			arr[j++]=i;
	}
	for(i=0;i<n;i++)
		printf("%d ", arr[i]);
}
