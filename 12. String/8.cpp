/*********************************************
*
*  Wildcard pattern matching in a string
*
*/////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

bool patternMatch(char str[],char pattern[], int n, int m)
{
    //empty pattern match only with empty string
    if(m==0)
        return (n==0);

    //table to save result
    bool table[n+1][m+1];

    //initialize table with false
    memset(table, false, sizeof(table));

    //both text and pattern are empty so they will match
    table[0][0] = true;

    //in this case text is empty and pattern is * so this will always match so all values will be true
    for(int j=1;j<=m;j++)
        if(pattern[j-1] == '*')
            table[0][j] = table[0][j-1];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(pattern[j-1] == '*')
                table[i][j] = table[i][j-1] || table[i-1][j];

            else if(pattern[j-1] == '?' || str[i-1] == pattern[j-1])
                table[i][j] = table[i-1][j-1];
            else
                table[i][j] = false;
        }
    }
    return table[n][m];
}

int main()
{
    char str[] = "baaabab";
    char pattern[] = "*****ba*****ab";
    if (patternMatch(str, pattern, strlen(str), strlen(pattern)))
        cout<<"Pattern matches String";
    else
        cout<<"Pattern does not match string";
    return 0;
}
