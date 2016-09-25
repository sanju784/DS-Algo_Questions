/**
 * Recursively remove similar adjacent characters from a string
 */
#include <stdio.h>
#include <string.h>

char* removeAdjacentPair(char *str, char *last_removed) {
	if(str[0] == '\0' || str[1] == '\0')
		return str;

	if(str[0] == str[1])
	{
		*last_removed = str[0];
		while(str[1] && str[0] == str[1])
			str++;
		str++;
		return removeAdjacentPair(str, last_removed);
	}

	char *rem_str = removeAdjacentPair(str+1, last_removed);

	if(rem_str[0] && rem_str[0] == str[0])
	{
		*last_removed = str[0];
		return (rem_str+1);
	}

	if(rem_str[0] == '\0' && *last_removed == str[0])
		return rem_str;

	rem_str--;
	rem_str[0] = str[0];
	return rem_str;
}

char *removePair(char *str) {
	char last_removed = '\0';
	return removeAdjacentPair(str, &last_removed);
}

void main() {
	char str[] = "ABCCBCBA";
	printf("%s", removePair(str));
}