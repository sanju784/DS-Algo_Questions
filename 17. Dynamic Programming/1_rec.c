/*********************************************
*
*  Find T(n) = 2*T(n-1)*T(n-2) by recursion
*
*/////////////////////////////////////////////

#include <stdio.h>

int calculate(int n)
{
    int sum = 0,i;
    if(n <=1)
        return 2;
    else
      return 2*calculate(i)*calculate(i-1);
}

void main()
{
    int n = 3;
    printf("%d", calculate(n));
}
