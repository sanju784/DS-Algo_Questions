/**
 * Alternate sorting, max at first then min, then 2nd max 2nd min, so on
 */

#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
	sort(arr, arr+n);
	int i=0, j=n-1;
	int temp[n];
	int index=0;
	while(i < j)
	{
		temp[index++] = arr[j--];
		temp[index++] = arr[i++];
	}
	if(n%2 == 1)
		temp[index] = arr[n/2];
	
	for(int i=0;i<n;i++)
		arr[i] = temp[i];
}

int main()
{
    int arr[] = {1, 12, 4, 6, 7, 10, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}