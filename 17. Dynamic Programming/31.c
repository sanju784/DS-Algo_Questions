/**
*  Given 2 strings and certain operations such as edit, delete and add
*  Find minimum number of operations required to change one string to other
*/

#include <stdio.h>
#include <string.h>

int min(int x, int y, int z)
{
	int min = x;
	if(y<min)
		min = y;
	if(z<min)
		min = z;
	return min;
}

int editDistance(char *str1, char *str2, int m, int n)
{
	int dp[m+1][n+1];
	int i,j;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			//here if one string is empty then total operations required is equal to the 
			//characters in second string as all characters need to be added (this is base case)
			if(i==0)
				dp[i][j] = j;
			//here if one string is empty then total operations required is equal to the 
			//characters in second string as all characters need to be added (this is the base case)
			else if(j==0)
				dp[i][j] = i;
			//if two characters are same then we take diagonal value as here the number of
			//required operations will be same as the number of operations required by the previous value
			else if(str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1];
			//when both characters are different then we take minimum of the near by value and add 1 to it
			//this is so because in this case we perform only one operation i.e. either edit or delete
			else
				dp[i][j] = 1 + min(dp[i][j-1],
									dp[i-1][j],
									dp[i-1][j-1]);
		}
	}
	return dp[m][n];
}

void main()
{
	char str1[] = "sunday";
	char str2[] = "saturday";
	printf("Total edit operations %d", editDistance(str1, str2, strlen(str1), strlen(str2)));
}