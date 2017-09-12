/**
 * Optimal Strategy for a coin game
 * Select coin from first or last position to get maximum sum
 */
#include <stdio.h>

int min(int a, int b)
{
	return (a<b)?a:b;
}

int max(int a, int b)
{
	return (a>b)?a:b;
}

int optimalGameValue(int arr[], int n)
{
	//to store solution, only upper diagonal of the matrix is filled
	int table[n][n];
	int i,j,gap,x,y,z;
	
	//gap here is the number of coins taken, so j represents end index of coin
	for(gap=0;gap<n;gap++)
	{
		for(i=0,j=gap;j<n;i++,j++)
		{
			//x is the case when we select i th coin and
			//other player select i+1 th coin
			x = ((i+2) <= j) ? table[i+2][j] : 0;
			//x is the case when we select i th coin and
			//other player select j th coin
			y = ((i+1) <= (j-1)) ? table[i+1][j-1]:0;
			//when both we and second player select coin from other end
			// i.e. j and j-1
			z = (i <= (j-2)) ? table[i][j-2] : 0;
			
			table[i][j] = max(arr[i]+min(x,y), arr[j]+min(y,z));
		}
	}
	return table[0][n-1];
}

void main()
{
	int arr[] = {8, 15, 3, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Optimal Value = %d", optimalGameValue(arr, n));
}