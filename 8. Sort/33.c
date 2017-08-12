/*********************************************
*
*  Merge 2 sorted array
*
*/////////////////////////////////////////////

#include <stdio.h>

void merge(int a[], int m, int b[], int n) {
	int i=0, k = m+n-1;
	while(i<k && m>=0 && n>=0) {
		if(a[m-1] > b[n-1]){
			a[k] = a[m-1];
			m--;k--;
		} else {
			a[k] = b[n-1];
			n--;k--;
		}
	}
	while(n!=0) {
		a[k] = b[n-1];
		k--;n--;
	}
	while(m!=0) {
		a[k] = a[m-1];
		k--;m--;
	}
}

void main() {
	int a[7] = {2,3,7,8};
	int b[3] = {1,5,9};
	merge(a, 4, b, 3);
	int i;
	for(i=0;i<7;i++)
		printf("%d ", a[i]);
}