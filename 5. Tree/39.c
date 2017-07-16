/*********************************************
*
*  Find height of tree where its parent node are represented by array
*
*/////////////////////////////////////////////

#include <stdio.h>

void main() {
	int p[] = {-1, 0, 1, 6, 6, 0, 0, 2, 7};
	int i, j, currHeight, maxHeight = -1;

    int n = sizeof(p) / sizeof(p[0]);
	for(i = 0; i < n;i++) {
		currHeight = 0;
		j = i;
		while(p[j] != -1) {
			currHeight++;
			j = p[j];
		}
		if(currHeight > maxHeight) {
			maxHeight = currHeight;
		}
	}
	printf("\nThe maximum height of tree is %d", maxHeight);
}