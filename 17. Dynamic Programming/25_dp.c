/*********************************************
*
*  Find subset in an array which sums for Total
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int set[], int n, int sum)
{
    bool subset[n+1][sum+1];
    int i,j;

    // If sum is 0 then answer will always be true
    for(i=0;i<=n;i++)
        subset[i][0] = true;

    //If sum is not 0 and set is empty then answer will always be false
    for(i=1;i<=sum;i++)
        subset[0][i] = false;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(j<set[i-1])
                subset[i][j] = subset[i-1][j];
            else
                subset[i][j] = subset[i-1][j] || subset[i-1][j-set[i-1]];
        }
    }

    return subset[n][sum];
}

void main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set)/sizeof(set[0]);
    if (isSubsetSum(set, n, sum))
     printf("Subset with given sum exists");
    else
     printf("Subset with given sum does not exist");
}
