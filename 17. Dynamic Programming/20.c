/*********************************************
*
*  Longest Increasing subsequence in an array
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int lis(int arr[], int n)
{
    int *lis, i,j;
    lis = (int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
        lis[i] = 1;

    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    int max =0;
    for(i=0;i<n;i++)
        if(max < lis[i])
            max = lis[i];

    free(lis);
    return max;
}

void main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d", lis(arr, n));
}
