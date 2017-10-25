/**
 * Count all possible path from top-left to bottom-right in a matrix
 */
#include<bits/stdc++.h>
using namespace std;

int numberOfPaths(int m, int n)
{
    int table[m][n];
    for(int i =0;i<m;i++)
        table[i][0] = 1;
    for(int i=0;i<n;i++)
        table[0][i] = 1;

    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            table[i][j] = table[i-1][j]+table[i][j-1];

    return table[m-1][n-1];
}

int main()
{
    cout<<numberOfPaths(3, 3);
}


/**
 * This recursive way has too many overlapping, So not a good solution
 * Dynamic way is better as base case is known, so can be done easily in bottom-up manner
 *
int numberOfPaths(int m, int n)
{
    if(m==1 || n==1)
        return 1;
    return numberOfPaths(m-1, n) + numberOfPaths(m, n-1);
}

int main()
{
    cout<<numberOfPaths(3, 3);
}
*/
