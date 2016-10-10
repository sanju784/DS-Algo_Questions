/*********************************************
*
*  Find two elements in an array whose sum is closest to 0
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void exchange(int *a, int *b)
{
  int temp;
  temp = *a;
  *a   = *b;
  *b   = temp;
}

int partition(int arr[], int si, int ei)
{
  int x = arr[ei];
  int i = (si - 1);
  int j;
 
  for (j = si; j <= ei - 1; j++)
  {
    if(arr[j] <= x)
    {
      i++;
      exchange(&arr[i], &arr[j]);
    }
  }
 
  exchange (&arr[i + 1], &arr[ei]);
  return (i + 1);
}

void quickSort(int arr[], int si, int ei)
{
  int pi;
  if(si < ei)
  {
    pi = partition(arr, si, ei);
    quickSort(arr, si, pi - 1);
    quickSort(arr, pi + 1, ei);
  }
}

void minAbsSumPair(int arr[], int n) {
	int sum, min_sum = INT_MAX;
	int l=0,r=n-1;
	int min_l=l, min_r=r;
	quickSort(arr,l,r);
	while(l<r) {
		sum=arr[l]+arr[r];
		if(abs(sum) < abs(min_sum)) {
			min_sum =sum;
			min_l =l;
			min_r=r;
		}
		if(sum<0)
			l++;
		else
			r--;
	}
	printf("\nElements with minimum sum is %d , %d", arr[min_l], arr[min_r]);
}

void main()
{
  int arr[] = {1, 60, -10, 70, -80, 85};
  int n = sizeof(arr)/sizeof(arr[0]);
  minAbsSumPair(arr, n);
}