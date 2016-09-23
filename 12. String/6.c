/**
 * Reverse a String which is not editable
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverseConstStr(const char *str) {
	int start, end, len;
	char temp, *ptr=NULL;

	len = strlen(str);
	ptr = malloc(sizeof(char)*(len + 1));
	ptr = strcpy(ptr, str);

	for(start=0, end=len-1; start<=end;start++,end--)
	{
		temp = ptr[start];
		ptr[start]=ptr[end];
		ptr[end]=temp;
	}
	return ptr;
}

void main() {
	const char *str = "reverse";
	printf("%s", reverseConstStr(str));
}