/*********************************************
*
*  Find number of trailing 0 in factorail n
*
*/////////////////////////////////////////////

#include <stdio.h>

int getZero(int n) {
	if(n<5) return 0;
	int res=0;
	for(i=5; n/i>= 1;i*=5) {
		res = res + n/i;
	}
	return res;
}

void main() {
	int n =100;
	printf("Total 0's is %d", getZero(n));
}