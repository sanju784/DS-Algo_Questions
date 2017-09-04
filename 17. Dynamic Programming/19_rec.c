/*********************************************
*
*  Making value with Minimum Coins - By Recursion
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int V)
{
    if(V==0)
        return 0;
    int res = INT_MAX, i;

    for(i=0;i<n;i++)
    {
        if(coins[i] <= V)
        {
            int sub_res = minCoins(coins, n, V-coins[i]);

            if(sub_res != INT_MAX && sub_res+1 < res)
                res = sub_res+1;
        }
    }
    return res;
}

void main()
{
    int coins[] = {9,6,5,1};
    int V = 11;
    int n = sizeof(coins)/sizeof(coins[0]);
    printf("Minimum coins required is %d", minCoins(coins, n, V));
}
