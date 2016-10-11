/*********************************************
*
*  Find 3 element from an array whose sum is equal to k
*
*/////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

void find3Numbers(int arr[], int n, int sum) {
	int l,r;
	sort(arr, arr+n);

	for(int i=0;i<n-2;i++) {
		l=i+1;
		r=n-1;
		while(l<r) {
			if(arr[i] + arr[l] + arr[r] == sum){
				printf("The numbers are %d, %d, %d", arr[i], arr[l], arr[r]);
				return;
			}
			else if(arr[i] + arr[l] + arr[r] < sum)
				l++;
			else
				r--;
		}
	}
}

int main() {
	int A[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int arr_size = sizeof(A)/sizeof(A[0]);
 
    find3Numbers(A, arr_size, sum);
 
    return 0;
}