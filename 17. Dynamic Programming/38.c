/**
 * Collect maximum coins when moving across a matrix
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define R 5
#define C 5

int max(int a, int b)
{
	return (a>b)?a:b;
}

bool isValid(int i, int j)
{
	return (i>=0 && i<R && j>=0 && j<C);
}

int maxCoinsUtil(char arr[R][C], int i, int j, int dir, int dp[R][C][2])
{
	if(isValid(i,j) == false || arr[i][j] == '#')
		return 0;
	
	if(dp[i][j][dir] != -1)
		return dp[i][j][dir];
	
	dp[i][j][dir] = (arr[i][j] == 'C')?1:0;
	
	if(dir == 1)
		dp[i][j][dir] += max(maxCoinsUtil(arr, i+1, j, 0, dp),
							maxCoinsUtil(arr, i, j+1, 1, dp));
							
	if(dir==0)
		dp[i][j][dir] += max(maxCoinsUtil(arr, i+1,j,1,dp),
							maxCoinsUtil(arr, i, j-1, 0, dp));
							
	return dp[i][j][dir];
}

int maxCoins(char arr[R][C])
{
	//initialize all values with -1
	int dp[R][C][2];
	memset(dp, -1, sizeof(dp));
	
	return maxCoinsUtil(arr,0,0,1,dp);
}

void main()
{
	char arr[R][C] = { {'E', 'C', 'C', 'C', 'C'},
                       {'C', '#', 'C', '#', 'E'},
                       {'#', 'C', 'C', '#', 'C'},
                       {'C', 'E', 'E', 'C', 'E'},
                       {'C', 'E', '#', 'C', 'E'}
                     };
					 
	printf("Maximum collected coins : %d", maxCoins(arr));
}