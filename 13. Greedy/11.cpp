/**
 * Greedy Algo to find minimum coins
 */

#include <bits/stdc++.h>

using namespace std;

int coins[] = {1,2,5,10,20,50,100,500,1000};
int n = sizeof(coins)/sizeof(coins[0]);

void findMin(int V)
{
	vector<int> ans;
	for(int i=n-1;i>=0;i--)
	{
		while(V >= coins[i])
		{
			V -= coins[i];
			ans.push_back(coins[i]);
		}
	}
	
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
}

int main()
{
	int v = 93;
	cout<<"Total change needed for "<<v<<" is ";
	findMin(v);
	return 0;
}