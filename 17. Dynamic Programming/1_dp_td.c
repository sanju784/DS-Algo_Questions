/*********************************************
*
*  Find T(n) = 2*T(n-1)*T(n-2) using dynamic Programming by Memorization (Top Down)
*
*/////////////////////////////////////////////

#include <stdio.h>
#define NIL -1
#define MAX 100

int T[MAX];

void init()
{
    int i;
    for(i=0;i<MAX;i++)
        T[i] = NIL;
}

int calculate(int n)
{
    if(T[n] == NIL){
        if(n<=1)
            T[n] = 2;
        else
            T[n] = 2*calculate(n-1)*calculate(n-2);
    }
    return T[n];
}

void main()
{
    int n = 3;
    init();
    printf("result %d", calculate(n));
}
