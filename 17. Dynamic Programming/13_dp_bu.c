/*********************************************
*
*  Find Catalan Number - In Bottom-Up way of Dynamic Programming
*
*/////////////////////////////////////////////

#include <stdio.h>

int catalan(int n)
{
    int cat[n+1];
    cat[0] = 1;
    cat[1] = 1;
    int i, j;
    for(i=2;i<=n;i++)
    {
        cat[i] = 0;
        for(j=0;j<i;j++)
            cat[i] += cat[j]*cat[i-j-1];
    }
    return cat[n];
}

void main()
{
    int i;
    for(i=0;i<10;i++)
        printf("%d ", catalan(i));
}
