/**
 * Reverse a String
 */
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void reverseStr(char *str) {
	int n = strlen(str);
	int i;
	for(i=0;i<n/2;i++)
		swap(&str[i], &str[n-i-1]);
}

void main() {
	char str[] = "reverse";
	reverseStr(str);
	printf("%s", str);
}