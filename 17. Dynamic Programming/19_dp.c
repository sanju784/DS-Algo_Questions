/*********************************************
*
*  Making value with Minimum Coins
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int V)
{
    int table[V+1];
    table[0]=0;
    int i, j;
    for(i=1;i<=V;i++)
        table[i] = INT_MAX;

    for(i=1;i<=V;i++)
    {
        for(j=0;j<n;j++)
        {
            if(coins[j] <= i)
            {
                int sub_res = table[i-coins[j]];
                if(sub_res != INT_MAX && sub_res+1 < table[i])
                    table[i] = sub_res+1;
            }
        }
    }
    return table[V];
}

void main()
{
    int coins[] = {9,6,5,1};
    int V = 11;
    int n = sizeof(coins)/sizeof(coins[0]);
    printf("Minimum coins required is %d", minCoins(coins, n, V));
}
