/**
 * Minimum number of railway platform needed
 */
#include <bits/stdc++.h>

using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
	sort(arr, arr+n);
	sort(dep, dep+n);
	
	int platform_needed = 1, result=1;
	int i=1, j=0;
	
	while(i < n && j < n)
	{
		if(arr[i] < dep[j])
		{
			platform_needed++;
			i++;
			
			if(platform_needed > result)
				result = platform_needed;
		}
		else
		{
			platform_needed--;
			j++;
		}
	}
	return result;
}

int main()
{
	int arr[] = {900,  940,  950, 1100, 1500, 1800};
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Minimum platform required "<<findPlatform(arr, dep, n);
	return 0;
}