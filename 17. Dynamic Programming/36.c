/**
 * Longest Palindrome Substring
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//To print substring
void printSubstring(char *str, int low, int high)
{
	int i;
	for(i=low;i<=high;i++)
		printf("%c", str[i]);
}

void longestPalindromeStr(char * str)
{
	int n = strlen(str);
	
	int i,j,k;
	
	//the value of table is true if substring is palindrome, otherwise false
	//here upper half of the matrix is only filled
	bool table[n][n];
	//filling table with false
	memset(table, 0, sizeof(table));
	
	//single character of string is palindrome
	int maxLength = 1;
	for(i=0;i<n;i++)
		table[i][i] = true;
	
	//start to save first position of palindromic substring
	int start = 0;
	//check for substring of length 2
	//if first and last character are same then it is palindome
	for(i=0;i<n-1;i++)
	{
		if(str[i] == str[i+1])
		{
			table[i][i+1] = true;
			start = i;
			int maxLength = 2;
		}
	}
	
	//check for substring of length greater than 2
	// here k is length of substring
	//i is first index of substring
	//j is last index of substring
	for(k=3;k<=n;k++)
	{
		for(i=0;i<n-k+1;i++)
		{
			j = i+k-1;
			
			//the string of length k is palindrome if char at i and j is same
			//value at table[i+1][j-1] is true, i.e. at lower diagonal position
			if(table[i+1][j-1] && str[i] == str[j])
			{
				table[i][j] = true;
				if(k > maxLength)
				{
					start = i;
					maxLength = k;
				}
			}
		}
	}
	
	printf("Longest Palindrome Substring : ");
	printSubstring(str, start, start+maxLength-1);
}

void main()
{
	char str[] = "XYXABCDCBAYZY";
	longestPalindromeStr(str);
}