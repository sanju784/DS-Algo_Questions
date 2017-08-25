/*********************************************
*
*  Find T(n) = 2*T(n-1)*T(n-2) using dynamic Programming by Tabulation (Bottom Up)
*
*/////////////////////////////////////////////

#include <stdio.h>
#define MAX 100

int T[MAX];

int calculate(int n)
{
    T[0] = T[1] = 2;
    int i;
    for(i=2;i<=n;i++)
        T[i] = 2*T[i-1]*T[i-2];
    return T[n];
}

void main()
{
    int n = 3;
    printf("%d", calculate(n));
}
