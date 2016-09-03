/*********************************************
*
*  Find number in 2D array
*
*/////////////////////////////////////////////

#include <stdio.h>

void search(int mat[4][4], int n, int k) {
    int i=0, j= n-1;
    while(i<n && j>=0) {
        if(mat[i][j] == k)
        {
           printf("%d is at %d,%d", k, i,j);
           return;
        }
        if(mat[i][j] > k)
            j--;
        else
            i++;
    }
}

void main() {
    int mat[4][4] = {
        {1,5,10,30},
        {3,15,45,60},
        {6,18,50,65},
        {9,20,61,99},
    };
    int n = 4, key = 45;
    search(mat, n, key);
}
