/*********************************************
*
*  Find Longest Consequitive Subsequence in an array
*
*/////////////////////////////////////////////

#include <stdio.h>

int getMaxSum(int arr[], int n)
{
    int max_sum_here = 0, max_so_far = 0, i;
    int start = 0, end = 0, s = 0;
    for(i=0;i<n;i++)
    {
        max_sum_here += arr[i];
        if(max_sum_here < 0){
            max_sum_here=0;
            s = i+1;
        }
        if(max_so_far < max_sum_here)
        {
            max_so_far = max_sum_here;
            start = s;
            end = i;
        }
    }
    printf("Start : %d \nEnd   : %d \n", start, end);
    return max_so_far;
}

void main()
{
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\nMaximum sum is %d", getMaxSum(arr, n));
}
