/*********************************************
*
*  Integer Knapsack Problem - WIth duplicate items permitted
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a>b)?a:b;
}

int getUnboundKnapsack(int W, int n, int val[], int wt[])
{
    int dp[W+1];
    memset(dp, 0, sizeof(dp));

    int i, j;

    for(i=0; i<=W;i++)
        for(j=0;j<n;j++)
           if(wt[j]<=i)
              dp[i] = max(dp[i], dp[i-wt[j]]+val[j]);

    return dp[W];
}

void main()
{
    int W = 8;
    int val[] = {10,40,50,70};
    int wt[] = {1,3,4,5};
    int n = sizeof(val)/sizeof(val[0]);

    printf("Maximum value = %d", getUnboundKnapsack(W, n, val, wt));
}
