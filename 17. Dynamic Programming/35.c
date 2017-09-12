/**
 * Longest Palindrome subsequence
 */
#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	return (a>b)?a:b;
}

int lps(char *str)
{
	int n = strlen(str);
	//L is length of substring
	int i,j,L;
	//table to store result, only upper half of diagonal is filled
	int table[n][n];
	
	//string of length 1 is palindrome of length 1
	//so filling all possible case of L=1 with 1
	for(i=0;i<n;i++)
	  table[i][i] = 1;
	
	for(L=2;L<=n;L++)
	{
		// i is starting index of substring L
		// j is end index of substring L
		for(i=0; i<n-L+1; i++)
		{
			j=i+L-1;
			//if L=2 and first and last character of string is same
			//then lps is 2
			if(str[i] == str[j] && L==2)
				table[i][j] = 2;
			//if first and last character of string is same
			// then lps is 2+(diagonally left value of table) 
			else if(str[i] == str[j])
				table[i][j] = table[i+1][j-1] + 2;
			//if first and last character of string are not same
			// then lps is maximum of left or bottom value oftable[i][j] 
			else
				table[i][j] = max(table[i][j-1], table[i+1][j]);
		}
	}
	return table[0][n-1];
}

void main()
{
	char seq[] = "BBABCBCAB";
	printf("Length = %d", lps(seq));
}