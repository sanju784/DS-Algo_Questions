/**
 * Find number of ways tiling of 2*n strip can be done from tile of size 2*1
 */

//This is same as Fibonacci number
//The only difference here is that F[0]=1,F[1]=2
//And the result is stored at n-1 position

#include <stdio.h>

int tiling(int n)
{
	int f[n];
	int i;
	
	f[0] = 1, f[1] = 2;
	for(i=2;i<n;i++)
	{
		f[i] = f[i-1] + f[i-2];
	}
	return f[n-1];
}

void main()
{
	int n = 4; //floor length
	printf("Total possible ways of tiling = %d", tiling(n));
}