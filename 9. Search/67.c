/*********************************************
*
*  Seperate Odd and Even numbers in an array
*
*/////////////////////////////////////////////

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void segregateEvenOdd(int arr[], int n) {
    int left =0, right = n-1;
    while(left < right) {
        while(arr[left] % 2 == 0 && left < right)
            left++;
        while(arr[right] % 2 == 1 && left < right)
            right--;
        if(left < right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

void main() {
    int arr[] = {4, 3, 1, 14, 16, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    segregateEvenOdd(arr, n);
    int i=0;
    printf("result array ");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
}
