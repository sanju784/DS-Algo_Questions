/**
 * Get highest of duplicate in array
 */
#include <bits/stdc++.h>
using namespace std;

int getHighIndex(int a[], int n)
{
	unordered_set<int> s;
	int last=-1;
	for(int i=0;i<n;i++)
	{
		if(s.find(a[i]) == s.end())
		{
			s.insert(a[i]);
		}else{
			last = i;
	    }
	}
	return last;
}

int main()
{
	int arr[] = {1,1,3,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int res = getHighIndex(arr, n);
	if(res == -1)
		printf("No duplicates");
	else
	    printf("Highest index at %d", res);
}
