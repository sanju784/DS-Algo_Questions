/*********************************************
*
*  merge two binary max-heaps
*
*/////////////////////////////////////////////

#include <stdio.h>

int getParent(int i) {
	int p = (i - 1) / 2;
	if(p < 0)
		return -1;
	else
		return p;
}


void mergeHeap(int h1[], int n1, int h2[], int n2) {
	int i = 0;
	while(i < n2) {
		h1[n1+i] = h2[i];
		int c = n1+i;
		int p = getParent(c);
		while(h1[p] < h1[c] && p != -1) {
			int temp = h1[p];
			h1[p] = h1[c];
			h1[c] = temp;
			c = p;
			p = getParent(c);
		}
		i++;
	}
}

void main() {
	int heap1[] = {10,5,6,1,2,3,4};
	int heap2[] = {9,8,7};
	int n1 = sizeof(heap1)/sizeof(heap1[0]);
	int n2 = sizeof(heap2)/sizeof(heap2[0]);
	int mergedHeap[n1+n2];
	int i;
	for(i=0;i<n1;i++)
		mergedHeap[i]=heap1[i];
	mergeHeap(mergedHeap, n1, heap2, n2);
	for(i=0;i<n1+n2;i++)
		printf("%d ", mergedHeap[i]);
}