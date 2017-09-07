/*********************************************
*
*  Generate all possible strings of size k
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

void k_str (char *arr, int n, int k, char *temp, int i) {
	int j,l;
	if(i == k) {
		  printf("%s\n", temp);
		  return;
	} else {
	for(l = 0; l < n; l++) {
		temp[i] = arr[l];
		k_str(arr, n, k, temp, i+1);
	}
  }
}

void all_combi(char *arr, int n, int k) {
	char temp[k];
	k_str(arr, n, k, temp, 0);
}

int main() {
	char arr[] = {'a', 'b'};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	all_combi(arr, n, k);
	return 0;
}
