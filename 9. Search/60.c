/*********************************************
*
*  Find number appear only once in an array
*
*/////////////////////////////////////////////

#include <stdio.h>

int getAlone(int arr[], int n) {
    int i, res = arr[0];
    for(i=1;i<n;i++){
        res ^= arr[i];
    }
    return res;
}

void main(){
  int arr[] = {1,2,1,3,2};
  int n=sizeof(arr)/sizeof(arr[0]);
  printf("%d is alone", getAlone(arr, n));
}
