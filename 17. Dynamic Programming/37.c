/**
 * Given 2 string S and T find number of times S appears in T
 */
#include <stdio.h>
#include <string.h>

int count(char *a, char *b)
{
	int m = strlen(a);
	int n = strlen(b);
	
	//table to store result
	int table[m+1][n+1];
	int i,j;
	
	//If both string are empty then one subsequence possible
	table[0][0] = 1;
	
	//If second String is empty
	//Then one subsequence is possible for character of first string
	for(i=1;i<=m;i++)
		table[i][0] = 1;
	
	//If first String is empty
	//Then no subsequence possible
	for(i=1;i<=n;i++)
		table[0][i] = 0;
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			//if both characters are same
			//then subseuence is sum of 
			if(a[i-1] == b[j-1])
				table[i][j] = table[i-1][j-1] + table[i-1][j];
			//if characters are not same
			//then length subsequence is same as previous value
			else
				table[i][j] = table[i-1][j];
		}
	}
	return table[m][n];
}

void main()
{
	char str1[] = "abadcb";
	char str2[] = "ab";
	printf("Total substring subsequence is %d", count(str1, str2));
}