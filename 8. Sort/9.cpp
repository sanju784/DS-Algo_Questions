/*********************************************
*
*  Find a and b from 2 array such that a+b=k
*
*/////////////////////////////////////////////


//compile with g++ -std=c++0x 9.cpp

#include <bits/stdc++.h>

using namespace std;

void findPair(int a1[], int a2[], int n1, int n2, int x) {
	unordered_set<int> s;
	for(int i=0;i<n1;i++)
		s.insert(a1[i]);
	for(int j=0;j<n2;j++)
		if(s.find(x-a2[j]) != s.end())
			cout<<x-a2[j] <<" "<<a2[j]<<endl;
}

int main() {
	int arr1[] = {1, 0, -4, 7, 6, 4};
    int arr2[] = {0 ,2, 4, -3, 2, 1};
    int x = 8;
    int n = sizeof(arr1)/sizeof(int);
    int m = sizeof(arr2)/sizeof(int);
    findPair(arr1, arr2, n, m, x);
	return 0;
}

/**


*/