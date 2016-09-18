/**
 * In an array find pair of number whose sum is S
 */

//compile by g++ -std=c++0x 16.cpp

#include <bits/stdc++.h>

using namespace std;

void printPairs(int a[], int n, int x) {
	unordered_set<int> h;
	for(int i =0;i<n;i++)
	{
		if(h.find(x-a[i]) != h.end())
			cout<<"("<<a[i]<<", "<<x-a[i]<<")"<<endl;
		else
			h.insert(a[i]);
	}
}

int main() {
    int a[] = {1, 12, 4, 45, 6, 10, 8, 8};
    int n = sizeof(a)/sizeof(a[0]);
    int x = 16;
    printPairs(a, n, x);
	return 0;
}