/*********************************************
*
*  Nuts and Bolts Problem
*
*/////////////////////////////////////////////

#include <stdio.h>

void swap(char *a, char *b){
	char temp = *a;
	*a=*b;
	*b = temp;
}

int partition(char arr[], int low, int high, char pivot) {
	int i = low, j;
	char temp1, temp2;
	for(j=low; j<high;j++) {
		if(arr[j] < pivot){
			swap(&arr[j], &arr[i]);
			i++;
		} else if(arr[j] ==pivot) {
			swap(&arr[j], &arr[high]);
			j--;
		}
	}
	swap(&arr[i], &arr[high]);
	return i;
}

void matchPairs(char nuts[], char bolts[], int low, int high) {
	if(low < high) {
		int pivot = partition(nuts, low, high, bolts[high]);

		partition(bolts, low, high, nuts[pivot]);

		matchPairs(nuts, bolts, low, pivot-1);
		matchPairs(nuts, bolts, pivot+1, high);
	}
}

void main() {
	char nuts[] = {'@', '#', '$', '%', '&', '*'};
	char bolts[] = {'$', '%', '@', '*', '#', '&'};
	matchPairs(nuts, bolts, 0, 5);
	int i;
	printf("\nNuts ");
	for(i=0;i<6;i++)
		printf("%c ", nuts[i]);
	printf("\nBolts");
	for(i=0;i<6;i++)
		printf("%c ", bolts[i]);
}