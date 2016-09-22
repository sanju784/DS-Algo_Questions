/*********************************************
*
*  Find length of longest common substring in 2 string
*
*/////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

int longestSubstr(char *X, char *Y, int m, int n)
{
    //table[i][j] contains length of longest common substring in X[0..i-1] and Y[0..j-1]
    int table[m+1][n+1];
    int result = 0;

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            //no common string if length of any of the string is 0
            if(i==0 || j==0)
                table[i][j] = 0;
            else if(X[i-1] == Y[j-1])
            {
                table[i][j] = table[i-1][j-1]+1;
                result = max(result, table[i][j]);
            }
            else
                table[i][j] = 0;
        }
    }
    return result;
}

int main()
{
    char str1[] = "abcdxyz";
    char str2[] = "xyzabcd";

    int m = strlen(str1);
    int n = strlen(str2);

    cout<<"Length of Common Substring is "<<longestSubstr(str1, str2, m, n);
    return 0;
}
