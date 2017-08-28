/*********************************************
*
*  Matrix Product Parenthesizations - By Recursion
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <limits.h>

int matrixChainMultiplication(int arr[], int i, int j)
{
    if(i==j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    for(k=i;k<j;k++)
    {
        count = matrixChainMultiplication(arr, i, k) +
                matrixChainMultiplication(arr, k+1, j) +
                arr[i-1]*arr[k]*arr[j];

        if(count < min)
            min = count;
    }
    return min;
}

void main()
{
    int arr[] = {40,20,30,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Minimum needed multiplication is %d", matrixChainMultiplication(arr, 1, n-1));
}
