/**
 * Rearrange array a1a2a3a4b1b2b3b4 in a1b1a2b2a3b3a4b4
 */
#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void shufleArray(int a[], int start, int end)
{
	if(end - start == 1)
		return;
	
	int mid = (start + end)/2;
	
	int temp = mid+1;
	int mmid = (start + mid) / 2;
	int i;
	for(i=mmid+1;i <= mid; i++)
		swap(&a[i], &a[temp++]);
	
	shufleArray(a, start, mid);
	shufleArray(a, mid+1, end);
}

void main()
{
	int a[] = {1,3,5,7,2,4,6,8};
	int n = sizeof(a)/sizeof(a[0]);
	
	shufleArray(a, 0, n-1);
	printf("Array after shufle is \n");
	int i;
	for(i=0;i<n;i++)
		printf("%d ", a[i]);
}