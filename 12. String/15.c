/**
 * Print all interleavings of a two string
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStrRec(char *str1, char *str2, char *iStr, int m, int n, int i)
{
	if(m==0 && n==0)
		printf("%s\n", iStr);
	
	if(m!=0)
	{
		iStr[i] = str1[0];
		printStrRec(str1+1, str2, iStr, m-1, n, i+1);
	}
	
	if(n != 0)
	{
		iStr[i] = str2[0];
		printStrRec(str1, str2+1, iStr, m, n-1, i+1);
	}
}

void printStr(char *str1, char *str2, int m, int n)
{
	char *iStr = (char*)malloc((m+n+1)*sizeof(char));
	iStr[m+n] = '\0';
	printStrRec(str1, str2, iStr, m, n, 0);
	free(iStr);
}

void main() {
	char str1[] = "AB";
	char str2[] = "CD";
	printStr(str1, str2, strlen(str1), strlen(str2));
}