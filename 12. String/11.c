/**
 * Combination of a String
 */
#include <stdio.h>
#include <string.h>

void combinationUtil(char str[], int n, int r, int index, char res[], int i)
{
	if(index == r)
	{
		printf("%s\n", res);
		return;
	}
	if(i>n)
		return;
	
	res[index] = str[i];
	combinationUtil(str, n, r, index+1, res, i+1);

    combinationUtil(str, n, r, index, res, i+1);	
}

void printCombination(char str[], int n, int r)
{
	char res[r+1];
	res[r] = '\0';
	combinationUtil(str, n, r, 0, res, 0);
}

void main() {
	char str[] = "abcde";
	int r = 3;
	int n = strlen(str);
	printCombination(str, n, r);
}