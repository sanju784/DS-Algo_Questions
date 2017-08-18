/*********************************************
*
*  Find second smallest number in array
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <limits.h>

void secondSmallest(int arr[], int n) {
    int i, first, second;
    first=second=INT_MAX;
    for(i=0;i<n;i++){
        if(arr[i] <first) {
            second = first;
            first = arr[i];
        } else if(arr[i] <second && arr[i] != first)
            second = arr[i];
    }
    printf("%d", second);
}

void main() {
    int arr[] = {12, 13, 1, 10, 34, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    secondSmallest(arr, n);
}
