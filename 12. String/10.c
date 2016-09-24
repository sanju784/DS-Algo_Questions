/**
 * Permutations of a String (Anagrams)
 */
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char *a, int l, int r) {
	int i;
	if(l==r)
		printf("%s\n", a);
	else
	{
		for(i=l;i<=r;i++)
		{
			swap((a+l), (a+i));
			permute(a, l+1, r);
			swap((a+l), (a+i));
		}
	}
}

void main() {
	char str[] = "ABC";
	int n = strlen(str);
	permute(str, 0, n-1);
}