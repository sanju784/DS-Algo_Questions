/*********************************************
*
*  Find Maximum subsequence sum such that no three elements are consequtive
*
*/////////////////////////////////////////////

#include <stdio.h>

int max(int a, int b)
{
    return (a>b)?a:b;
}

int maxSumWO3Conse(int arr[], int n)
{
    int sum[n];
    sum[0] = arr[0];
    sum[1] = arr[0] + arr[1];
    sum[2] = max(sum[1], arr[1] + arr[2]);
    int i;
    for(i=3;i<n;i++)
        sum[i] = max(max(sum[i-1], sum[i-2] + arr[i]), arr[i]+arr[i-1]+sum[i-3]);

    return sum[n-1];
}

void main()
{
    int arr[] = {3000, 2000, 1000, 3, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d", maxSumWO3Conse(arr, n));
}
