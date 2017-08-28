/*********************************************
*
*  Find Catalan Number - In Top-Down way of Dynamic Programming
*
*/////////////////////////////////////////////

#include <stdio.h>
#define NIL -1
#define MAX 100

int cat[MAX];

void init()
{
    int i;
    for(i=0;i<MAX;i++)
        cat[i] = NIL;
}

int catalan(int n)
{
    if(cat[n] == NIL)
    {
        if(n<=1)
            cat[n] = 1;
        else {
                int i;
                cat[n] = 0;
                for(i=0;i<n;i++)
                cat[n] += catalan(i)*catalan(n-i-1);
            }
    }
    return cat[n];
}

void main()
{
    init();
    int i;
    for(i=0;i<10;i++)
        printf("%d ", catalan(i));
}
