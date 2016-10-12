/*********************************************
*
*  Find 3 element from an array whose sum is closest to 0
*
*/////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

void find3Numbers(int arr[], int n) {
	int l,r;
	sort(arr, arr+n);

	for(int i=0;i<n-2;i++) {
		l=i+1;
		r=n-1;
		while(l<r) {
			if(arr[i] + arr[l] + arr[r] == 0){
				printf("\n%d, %d, %d", arr[i], arr[l], arr[r]);
				l++;r--;
			}
			else if(arr[i] + arr[l] + arr[r] < 0)
				l++;
			else
				r--;
		}
	}
}

int main() {
	int A[] = {0,-1,2,-3,1};
    int arr_size = sizeof(A)/sizeof(A[0]);


    printf("\nThe numbers are");
    find3Numbers(A, arr_size);
 
    return 0;
}