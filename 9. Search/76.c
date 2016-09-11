/*********************************************
*
*  Find j-i in an array where a[j] >a[i]
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
	return (a>b)?b:a;
}

int max(int a, int b) {
	return (a>b)?a:b;
}

int maxIndexDiff(int arr[], int n) {
	int maxDiff, i, j;
	int *LMin = (int*)malloc(sizeof(int)*n);
	int *RMax = (int*)malloc(sizeof(int)*n);
	LMin[0] = arr[0];
	for(i=1;i<n;i++)
		LMin[i] = min(arr[i], LMin[i-1]);
	RMax[n-1] = arr[n-1];
	for(j=n-2;j>=0;j--)
		RMax[j] = max(arr[j], RMax[j+1]);
	i=0, j=0, maxDiff=-1;
	while(j<n && i<n){
		if(LMin[i] < RMax[j])
		{
			maxDiff = max(maxDiff, j-i);
			j=j+1;
		}
		else
			i=i+1;
	}
	return maxDiff;
}

void main() {
	int arr[] = {34,8,10,3,2,80,30,33,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d is max index diff.", maxIndexDiff(arr, n));
}