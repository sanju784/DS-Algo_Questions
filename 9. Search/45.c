/*********************************************
*
*  Find median of all elements in a sorted array of size m and n
*
*/////////////////////////////////////////////

#include <stdio.h>

int max(int a, int b) {
	return (a>b)?a:b;
}

int min(int a, int b) {
	return (a<b)?a:b;
}

float MO2(int a, int b) {
	return (a+b)/2.0;
}

float MO3(int a, int b, int c){
	return (a+b+c - max(a, max(b,c)) - min(a, min(b,c)));
}

float MO4(int a, int b, int c, int d) {
	int Max = max(a, max(b, max(c,d)));
	int Min = min(a, min(b, min(c,d)));
	return (a+b+c+d - Min - Max)/2.0;
}

float medianSingle(int arr[], int n){
	if(n==0)
		return -1;
	if(n%2 == 0)
		return (arr[n/2] + arr[n/2-1])/2.0;
	return arr[n/2];
}

float findMedianUtil(int a[], int n, int b[], int m) {
	if(n==0)
		return medianSingle(b, m);
	if(n==1){
		if(m==1)
			return MO2(a[0], b[0]);
		if(m %2 == 1)
			return MO2(b[m/2], MO3(a[0], b[m/2-1], b[m/2+1]));
		return MO3(b[m/2], b[m/2-1], a[0]);
	}
	else if(n==2) {
		if(m ==2)
			return MO4(a[0], a[1], b[0], b[1]);
		if(m%2==1)
			return MO3(b[m/2], max(a[0], b[m/2-1]), min(a[1], b[m/2+1]));
		return MO4(b[m/2], b[m/2-1], max(a[0], b[m/2-2]), min(a[1], b[m/2+1]));
	}

	int idxA = (n-1)/2;
	int idxB = (m-1)/2;

	if(a[idxA] <= b[idxB])
		return findMedianUtil(a+idxA, n/2+1, b, m-idxA);

	return findMedianUtil(a, n/2+1, b+idxA, m-idxA);
}

float findMedian(int a[], int n, int b[], int m) {
	if(n>m)
		return findMedianUtil(b, m, a, n);
	else
		return findMedianUtil(a, n, b, m);
}

void main() {
	int a[] = {50, 100};
	int b[] = {5, 10, 15, 20, 25};
	printf("Median is %f", findMedian(a, 2, b, 5));
}