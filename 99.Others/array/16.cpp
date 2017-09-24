/**
 * segregate 0 and 1
 */

#include <bits/stdc++.h>
using namespace std;

void seggregate(int arr[], int n)
{
	int i=0, j=n-1;

	while(arr[i]==0 && i < j)
		i++;
	while(arr[j] == 1 && i < j)
		j--;
	
	while(i < j)
	{
		if(arr[i] == 1 && arr[j] == 0)
		{
			swap(arr[i], arr[j]);
		}
		i++;
		j--;
	}
}

int main()
{
    int arr[] = {0,1,1,0,1,1,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    seggregate(arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}