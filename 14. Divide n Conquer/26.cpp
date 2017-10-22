/**
 * Find Closest pair of points in 1 dimension
 */
#include <bits/stdc++.h>

using namespace std;

int getMinDistance(int p[], int n)
{
	sort(p, p+n);
	int min_dist = 0;
	for(int i=1;i<n;i++)
		if(p[i] - p[i-1] > min_dist)
			min_dist = p[i]-p[i-1];
	
	return min_dist;
}

int main()
{
	int pX[] = {5,7,1,9};
	int n = sizeof(pX)/sizeof(pX[0]);
	cout<<"The minimum distance is "<<getMinDistance(pX,n);
	return 0;
}