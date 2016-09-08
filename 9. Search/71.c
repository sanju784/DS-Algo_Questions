/*********************************************
*
*  Find maximum difference between two elements in an array
*
*/////////////////////////////////////////////

#include <stdio.h>

int maxDiff(int arr[], int n) {
    int maxDiff = -1, i;
    int maxRight = arr[n-1];
    for(i=n-2;i>=0;i--){
        if(arr[i] > maxRight)
            maxRight = arr[i];
        else
        {
            int diff= maxRight-arr[i];
            if(diff > maxDiff)
                maxDiff=diff;
        }
    }
    return maxDiff;
}

void main() {
    int arr[] = {80,2,6,3,100};
    int n = 5;
    printf("Maximum diff in array is %d", maxDiff(arr, n));
}
