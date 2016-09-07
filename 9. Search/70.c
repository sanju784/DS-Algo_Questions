/*********************************************
*
*  Sort an array with 0's 1's and 2's
*
*/////////////////////////////////////////////

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void segregate012(int arr[], int n) {
    int low =0, mid = 0, high = n-1;
    while(mid <= high) {
        switch(arr[mid]){
        case 0:
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(&arr[mid], &arr[high]);
            high--;
            break;
        }
    }
}

void main() {
    int arr[] = {0,2,1,0,0,2,1,0,1,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    segregate012(arr, n);
    int i=0;
    printf("result array ");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
}
