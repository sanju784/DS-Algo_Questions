/*********************************************
*
*  Find Local minimum in an array
*
*/////////////////////////////////////////////

#include <stdio.h>

int getLocalMin(int arr[], int low, int high, int n){
  int mid = low + (high - low)/2;
  if((mid==0 || arr[mid] < arr[mid-1]) && (mid == n-1 || arr[mid+1]>arr[mid]))
    return mid;
  else if(mid>0 && arr[mid-1] < arr[mid])
    return getLocalMin(arr, low, mid-1, n);
  return getLocalMin(arr, mid+1, high, n);
}

int localMin(int arr[], int n) {
    return getLocalMin(arr, 0, n-1, n);
}

void main() {
    int arr[] = {4, 3, 1, 14, 16, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Index of a local minima is %d", localMin(arr, n));
}
