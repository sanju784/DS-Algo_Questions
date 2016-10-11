/*********************************************
*
*  Find pythagorian triplet in array
*
*/////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void findTriplet(int arr[], int n) {
	for(int i=0;i<n;i++)
		arr[i] = arr[i]*arr[i];

	sort(arr, arr+n);

	for(int i=n-1;i>=2;i--){
		int l=0;
		int r=i-1;
		while(l<r){
			if(arr[l] + arr[r] == arr[i])
				cout<<sqrt(arr[i])<<" "<<sqrt(arr[l])<<" "<<sqrt(arr[r])<<endl;
			(arr[l]+arr[r]<arr[i] ? l++:r--);
		}
	}
}

int main() {
	int arr[] = {3, 1, 4, 6, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"\nThe pythagorian triplet in array are ";
	findTriplet(arr, n);
	return 0;
}