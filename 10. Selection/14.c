/**
 * Find Median of 2 arrays containing n elements
 */

#include <stdio.h>

int min(int a, int b) {
	return (a<b)?a:b;
}

int max(int a, int b) {
	return (a>b?a:b);
}

int median(int a[], int n) {
	if(n%2==0)
		return (a[n/2] + a[n/2-1])/2;
	else
	    return a[n/2];
}

float getMedian(int a[], int b[], int n) {
	if(n==1)
		return (a[0]+b[0])/2.0;
	if(n==2)
		return (max(a[0], b[0]) + min(a[1], b[1]))/2.0;
	int m1 = median(a, n);
	int m2 = median(b, n);
	if(m1 == m2)
		return m1;
	else if(m1 < m2) {
		if(n%2 == 0)
			return getMedian(a + n/2-1, b, n-n/2+1);
		return getMedian(a+n/2, b, n-n/2);
	}
	else
		if(n%2==0)
			return getMedian(b+n/2-1, a, n-n/2+1);
		return getMedian(b+n/2, a, n-n/2);
}

void main() {
	int a1[] = {1,3,7,8,9};
	int a2[] = {2,4,5,6,11};
	int n = sizeof(a1)/sizeof(a1[0]);

	printf("The median is %f", getMedian(a1, a2, n));
}