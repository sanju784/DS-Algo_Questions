/*********************************************
*
*  Find number that appears more than n/2 times in array
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>

int getMajority(int a[], int n){
    int maj_index=0, count =1;
    int i;
    for(i=1;i<n;i++){
        if(a[i]==a[maj_index])
            count++;
        else
            count--;
        if(count==0)
        {
            maj_index=i;
            count=1;
        }
    }
    return a[maj_index];
}

bool isMajority(int a[], int n, int num){
    int i, count=0;;
    for(i=0;i<n;i++){
        if(a[i]==num)
            count++;
    }
    if(count > n/2)
        return true;
    else
        return false;
}

void printMajority(int a[], int n) {
    int res = getMajority(a, n);
    if(isMajority(a, n, res))
        printf("%d", res);
}

void main(){
    int a[] = {1, 3, 3, 1, 2, 1, 1};
    int size = (sizeof(a))/sizeof(a[0]);
    printMajority(a, size);
}
