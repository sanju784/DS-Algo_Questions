/*********************************************
*
*  Seperate 0's and 1's in an array
*
*/////////////////////////////////////////////

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void segregateZeroOne(int arr[], int n) {
    int left =0, right = n-1;
    while(left < right) {
        while(arr[left] == 0 && left < right)
            left++;
        while(arr[right] == 1 && left < right)
            right--;
        if(left < right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

void main() {
    int arr[] = {0,1,0,0,1,0,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    segregateZeroOne(arr, n);
    int i=0;
    printf("result array ");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
}
