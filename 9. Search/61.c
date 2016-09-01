/*********************************************
*
*  Throwing Egg from n-storey building - dynamic
*
*/////////////////////////////////////////////

//Dynamic
#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a>b)?a:b;
}

int eggDrop(int n, int k) {
    int eggfloor[n+1][k+1];
    int res;
    int i,j,x;
    for(i=1;i<=n;i++){
        eggfloor[i][0] = 0;
        eggfloor[i][1] = 1;
    }

    for(j=1;j<=k;j++){
        eggfloor[1][j] = j;
    }

    for(i=2; i<=n;i++)
    {
        for(j=2;j<=k;j++)
        {
            eggfloor[i][j] = INT_MAX;
            for(x=1;x<=j;x++)
            {
                res = 1+max(eggfloor[i-1][x-1], eggfloor[i][j-x]);
                if(res < eggfloor[i][j])
                    eggfloor[i][j] = res;
            }
        }
    }
    return eggfloor[n][k];
}

void main() {
    int n = 2, k = 36;
    printf("Minimum number of trials %d", eggDrop(n,k));
}
