/**
 * segregate odd and even
 */

#include <bits/stdc++.h>
using namespace std;

void seggregate(int arr[], int n)
{
	int i=0, j=n-1;

	while(arr[i]%2 == 0 && i < j)
		i++;
	while(arr[j]%2 == 1 && i < j)
		j--;
	
	while(i < j)
	{
		if(arr[i]%2 == 1 && arr[j]%2 == 0)
		{
			swap(arr[i], arr[j]);
		}
		i++;
		j--;
	}
}

int main()
{
    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    seggregate(arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}