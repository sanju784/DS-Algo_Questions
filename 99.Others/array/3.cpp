/**
 * Maximum value of sum(i*arr[i])
 */

#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n)
{
    int arr_sum=0, curr_sum = 0;
    for(int i=0;i<n;i++)
    {
        arr_sum += arr[i];
        curr_sum = curr_sum + (i*arr[i]);
    }
    int maxVal = curr_sum;

    for(int i=1;i<n;i++)
    {
        curr_sum = curr_sum + arr_sum - n*arr[n-i];
        if(curr_sum > maxVal)
            maxVal = curr_sum;
    }
    return maxVal;
}

int main()
{
    int arr[] = {4,5,6,7,8,9,1,2,3};
    int n = 9;
    cout<<maxSum(arr, n);
}
