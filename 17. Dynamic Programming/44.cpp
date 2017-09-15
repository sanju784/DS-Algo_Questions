/**
 * Find minimum number of squares needed to form a number
 */
#include <bits/stdc++.h>

using namespace std;

int getMinSquare(int n)
{
	int dp[n+1];
	
	//base case
	dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3;
	
	for(int i = 4;i<=n;i++)
	{
		//maximum possible value (if it is sum of all squares of 1)
		dp[i] = i;
		for(int x=1;x<=i;x++)
		{
			int temp = x*x;
			if(temp>i)
				break;
			else
				dp[i] = min(dp[i], 1+dp[i-temp]);
		}
	}
	return dp[n];
}

int main()
{
	int n = 6;
	cout<<"Minimum squares for "<<n<<" is "<<getMinSquare(n);
	return 0;
}