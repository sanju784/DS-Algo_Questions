/**
 * Calculate k^n
 */
#include <stdio.h>

int exponential(int k, int n)
{
	if(k==0)
		return 0;
	if(n==0)
		return 1;
	if(n==1)
		return k;
	if(n%2 == 1)
	{
		return k*exponential(k, n-1);
	} else {
		return exponential(k, n/2)*exponential(k, n/2);
	}
}

void main()
{
	int k = 3, n = 12;
	printf("%d", exponential(k,n));
}