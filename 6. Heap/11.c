/*********************************************
*
*  All elements less than k in a binary heap
*
*/////////////////////////////////////////////

#include <stdio.h>

int getLChild(int i, int n) {
	int l = 2*i +1;
	if(l >= n)
		return -1;
	else
		return l;
}

int getRChild(int i, int n) {
	int r = 2*i + 2;
	if(r >= n)
		return -1;
	else
		return r;
}


void getLessThen(int heap[], int n, int k) {
	int i = 0;
	if(heap[i] < k)
		printf("%d ", heap[i]);
	else
		return;
	while(i < n) {
		int l = getLChild(i, n);
		int r = getRChild(i, n);
		if((heap[l] > k && heap[r] > k) || (l == -1 && r == -1))
			break;
		else if(heap[l] < k && heap[r] < k) {
			printf("%d ", heap[l]);
			printf("%d ", heap[r]);
			i++;
		} else if(l != -1 && heap[l] < k) {
		    printf("%d ", heap[l]);
		    i = l;
		} else if(r != -1 && heap[r] < k) {
		  	printf("%d ", heap[r]);
		  	i = r;
		} else
		    i++;
	}
}

void main() {
	int heap[] = {1, 2, 5, 3, 4, 6, 7};
	int n = sizeof(heap) / sizeof(heap[0]);
	int k;
	printf("\nEnter value of k : ");
	scanf("%d", &k);
	printf("\nThe heap values less then %d are ", k);
	getLessThen(heap, n , k);
}