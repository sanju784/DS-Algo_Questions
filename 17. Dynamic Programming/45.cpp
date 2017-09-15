/**
 * Minimum number of jumps needed to reach last position
 */
#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
	//this store the result to reach at position
	int jumps[n];
	int i,j;
	
	if(n == 0 || arr[0] == 0)
		return INT_MAX;
	
	//base case
	jumps[0] = 0;
	
	for(i=1;i<n;i++)
	{
		jumps[i] = INT_MAX;
		for(j=0;j<i;j++)
		{
			//j+arr[j] is the maximum value we can reach from j
			if(i <= j+arr[j] && jumps[j] != INT_MAX)
			{
				jumps[i] = min(jumps[i], jumps[j] + 1);
				break;
			}
		}
	}
	return jumps[n-1];
}

int main()
{
	int arr[] = {1,3,6,1,0,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Minimum required jumps = "<<minJumps(arr, n);
	return 0;
}

/**
  if(i<=j+arr[j])
    T[i] = min(T[i], T[j] + 1)
*/