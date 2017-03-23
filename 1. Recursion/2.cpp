#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void k_str (char arr[], int n, int k, char *temp) {
	int j,l;
	if(n == 0) {
		  cout<<temp<<endl;
	} else {
	for(l = 0; l < k; l++) {
		temp[n-1] = arr[l];
		k_str(arr, n-1, k, temp);
	}
}
}

int main() {
	char arr[] = {'a', 'b', 'c'};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	char *temp;
	temp = (char *)malloc(k*sizeof(char));
	k_str(arr, n, k, temp);
	return 0;
}