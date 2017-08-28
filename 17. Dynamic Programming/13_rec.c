/*********************************************
*
*  Find Catalan Number - Total number of possible BST from n vertices - By Recursion
*
*/////////////////////////////////////////////

#include <stdio.h>

int catalan(int n)
{
    if(n<=1)
        return 1;
    int res = 0, i;
    for(i=0;i<n;i++)
        res += catalan(i) * catalan(n-i-1);

    return res;
}

void main()
{
    int i;
    for(i=0;i<10;i++)
        printf("%d ", catalan(i));
}
