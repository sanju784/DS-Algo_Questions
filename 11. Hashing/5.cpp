/**
 * Check if two array have same set of numbers
 */

//compile by g++ -std=c++0x 5.cpp

#include <bits/stdc++.h>

using namespace std;

bool isEqual(int arr1[], int arr2[], int n, int m) {
	if(n!=m)
		return false;
	unordered_map<int, int> mp;
	for(int i=0;i<n;i++)
		mp[arr1[i]]++;

	for(int i=0;i<n;i++){
		if(mp.find(arr2[i]) == mp.end())
			return false;
		if(mp[arr2[i]] == 0)
			return false;
		mp[arr2[i]]--;
	}
	return true;
}

int main() {
	int arr1[] = {3,5,2,5,2};
	int arr2[] = {2,3,5,5,2};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	int m = sizeof(arr2)/sizeof(arr2[0]);
	if(isEqual(arr1, arr2, n, m))
		cout<<"both arrays are same";
	else
		cout<<"Arrays are not same.";
	return 0;
}