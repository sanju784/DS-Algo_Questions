/**
 * Find k'th smallest element in Union of 2 array
 */

#include <stdio.h>

int min (int a, int b) {
	(a>b) ? a : b;
}

int kth(int *a1, int *a2, int *end1, int *end2, int k) {
	if(a1==end1)
		return a2[k];
	if(a2== end2)
		return a1[k];
	int mid1 = (end1-a1) / 2;
	int mid2 = (end2-a2) / 2;
	if(mid1 + mid2 < k)
	{
		if(a1[mid1] > a2[mid2])
			return kth(a1, a2+mid2+1, end1, end2, k-mid2-1);
		else
			return kth(a1+mid1+1, a2, end1, end2, k-mid1-1);
	} else {
		if(a1[mid1] > a2[mid2])
			return kth(a1, a2, a1+mid1, end2, k);
		else
			return kth(a1, a2, end1, a2+mid2, k);
	}
}

void main() {
	int a1[] = {1,4,5,7,8};
	int a2[] = {2,3,6,9};
	int n1=sizeof(a1)/sizeof(a1[0]);
	int n2=sizeof(a2)/sizeof(a2[0]);
	int k = 5;
	printf("%d", kth(a1, a2, a1+n1, a2+n2, k-1));
}