/*********************************************
*
*  Delete i-th index element from a min-heap
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

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

void deletePos(int heap[], int pos, int n) {
	int min, temp, p;
	heap[pos] = heap[n-1];
	n--;
	while(pos < n) {
	  p = pos;
	  int l = getLChild(pos, n);
	  int r = getRChild(pos, n);
	  if(l == -1 && r == -1)
	  	break;
	  else if(l != -1 && r != -1) {
		if(heap[l] < heap[r]) {
			min = heap[l];
			pos = l;
		} else {
			min = heap[r];
			pos = r;
		}
	  }
	  else if(l != -1 && heap[pos] > heap[l]){
	  	min = heap[l];
	  	pos = l;
	  }
	  else if(r != -1 && heap[pos] > heap[r]) {
	  	min = heap[r];
	  	pos = r;
	  }
	  temp = heap[p];
	  heap[p] = min;
	  heap[pos] = temp;
    }
}

void main() {
	int heap[] = {1, 2, 5, 3, 4, 6, 7};
	int n = sizeof(heap) / sizeof(heap[0]);
	printf("\nEnter position you want to delete ");
	int pos;
	scanf("%d", &pos);
	deletePos(heap, pos, n);
	printf("\nNew heap ");
	int i;
	for(i=0; i < n-1; i++)
		printf(" %d", heap[i]);
}