/*********************************************
*
*  Find row with maximum number of 0 in a matrix
*
*/////////////////////////////////////////////

#include <stdio.h>

void search(int mat[4][4], int n) {
    int i, j=n-1, res=0, idx;
        while(mat[i][j] == 1 && j>=0) {
           j--;
        }
        idx = j+1;
        for(i=1;i<n;i++)
        {
            while(idx>=0 && mat[i][idx] == 1){
                idx--;
                res = i;
            }
        }
        printf("%d", res);
}

void main() {
    int mat[4][4] = {
        {0,1,1,1},
        {0,0,1,1},
        {1,1,1,1},
        {0,0,0,0},
    };
    int n = 4;
    search(mat, n);
}
