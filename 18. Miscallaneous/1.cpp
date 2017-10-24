/**
 * Print Matrix in Spiral Order
 */

#include <bits/stdc++.h>
using namespace std;

void printMatrix(int mat[][4], int m, int n)
{
    /*
       k - first row index
       m - last row index
       l - start column index
       n - last column index
    */
    int k=0,l=0, i;
    while(k<m && l<n)
    {
        for(i=l;i<n;i++)
            printf("%d ", mat[l][i]);
        k++;
        for(i=k;i<m;i++)
            printf("%d ", mat[i][n-1]);
        n--;

        if(k<m)
        {
            for(i=n-1;i>=l;i--)
                printf("%d ",mat[m-1][i]);
            m--;
        }
        if(l<n)
        {
            for(i=m-1;i>=k;i--)
                printf("%d ", mat[i][l]);
            l++;
        }
    }
}

int main()
{
    int mat [4][4] =
    {
        {1,2,3,4},
        {1,1,3,3},
        {2,1,3,1},
        {2,4,1,3},
    };

    printMatrix(mat, 4, 4);
}
