/**
 * In a BST each node has frequency Create Optimal BST such that total search time is reduced
 */

#include <stdio.h>
#include <limits.h>

// function to calculate sum of freq[] from i to j
int sum(int freq[], int i, int j)
{
	int sum = 0, k;
	for(k=i;k <=j;k++)
		sum += freq[k];
	return sum;
}

//in this only the upper half of the matrix(diagonal) is filled the lower half remains empty
int optimalSearchTree(int keys[], int freq[], int n)
{
	// This will contain the minimum cost of nodes
	int cost[n][n];
	
	int i, r, L;
	//for single key cost same as frequency
	//This is the case of L=1, from L=2 is below
	for(i=0;i<n;i++)
		cost[i][i] = freq[i];
	
	//here L is the number of key taken at this time and calcute minimum cost
	//first we take 1 key, then 2, then 3 and calculate the minimum cost with these keys
	for(L=2;L<=n;L++)
	{
		for(i=0;i<=n-L;i++)
		{
			//j to to check for all nodes from i to j of size L
			int j = i+L-1;
			cost[i][j] = INT_MAX;
	
			//to check for all nodes from i to j of size L and findings the minimum cost
			for(r=i;r<=j;r++)
			{
				int c = ((r>i)?cost[i][r-1]:0) +
						((r<j)?cost[r+1][j]:0) +
						sum(freq, i,j);
				
				if(c < cost[i][j])
					cost[i][j] = c;
			}
		}
	}
	return cost[0][n-1];
}

void main()
{
	int keys[] = {10,12,16,21};
	int freq[] = {4,2,6,3};
	int n = sizeof(keys)/sizeof(keys[0]);
	printf("Cost of Optimal Search is %d", optimalSearchTree(keys, freq, n));
}