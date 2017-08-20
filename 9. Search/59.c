/*********************************************
*
*  Find element that appear maximum number of times in array
*
*/////////////////////////////////////////////

#include <stdio.h>

int getMajority(int arr[], int n) {
    int maj_index=0, count=1;
    int i;
    for(i=1;i<n;i++){
        if(count==0){
            maj_index=i;
            count=1;
        }

        if(arr[maj_index] == arr[i])
            count++;
        else
            count--;
    }
    return arr[maj_index];
}

void main(){
  int arr[] = {1,1,1,4,3,2};
  int n=sizeof(arr)/sizeof(arr[0]);
  printf("%d is majority", getMajority(arr, n));
}
