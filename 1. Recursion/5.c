/*********************************************
*
*  program to find the maximum number of connected 1's in a 2D array
*  
* Example
*
* Input -
* 	11000
* 	01100
* 	00101
* 	10001
* 	01011
* Output - 5
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//This 2D array has to be created dynamically
//Because if not done so the address of array can't be returned
//as after exit from the function the allocated memory will be deleted from the stack

bool **create2darr(int r, int c) {
	int i,j;
	bool **arr = (bool **)malloc(r*sizeof(int *));
	int row;
	for(row = 0;row < r;row++) {
		arr[row] = (bool *)malloc(c*sizeof(int *));
	}
	for(i = 0;i < r;i++) {
		for(j = 0;j < c; j++) {
			arr[i][j] = false;
		}
	}
	return arr;
}

int getval(int (*A)[5], int i, int j, int L, int H) {
	if(i < 0 || i > L || j < 0 || j > H)
		return 0;
	else
		return A[i][j];
}

int findMaxBlock(int (*A)[5], int r, int c, int L, int H, bool **cntarr, int *size) {
	if(r >= L || c >= H)
		return;
	cntarr[r][c] = true;
	*size++;
	int direction[][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
	int i;
	for(i = 0;i < 8;i++) {
		int newi = r + direction[i][0];
		int newj = c + direction[i][1];
		int val = getval(A, newi, newj, L, H);
		if(val > 0 && cntarr[newi][newj] == false) {
			findMaxBlock(A, newi, newj, L, H, cntarr, size);
		}
	}
	cntarr[r][c] = false;
}

int getMaxOnes(int (*A)[5], int rmax, int colmax) {
	int maxsize = 0;
	int size = 0;
	int i, j;
	bool **cntarr = create2darr(rmax, colmax);
	for(i = 0;i < rmax; i++) {
		for(j = 0;j < colmax; j++) {
			if(A[i][j] == 1) {
				size = findMaxBlock(A, i, j, rmax, colmax, cntarr, 0);
				if(size > maxsize)
					maxsize = size;
			}
		}
	}
	return *maxadd;
}

void main() {
	int zarr[][5] = {{1,1,0,0,0},{0,1,1,0,1},{0,0,0,1,1},{1,0,0,1,1},{0,1,0,1,1}};
	int res = getMaxOnes(zarr, 5, 5);
	printf("%d\n",res );
}