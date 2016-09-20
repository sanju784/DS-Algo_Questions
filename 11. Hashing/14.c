/**
 * Find first non-repeated character in a string
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define NO_OF_CHARS 256

//To store total number of times a character is in string
//To store first index at which the character appears
typedef struct countIndex {
	int count;
	int index;
} countIndex;

countIndex *getCharCountArray(char * str) {
	countIndex *count = (countIndex*)calloc(sizeof(countIndex), NO_OF_CHARS);
	int i;
	for(i=0; *(str+i); i++)
	{
		(count[*(str+i)].count)++;

		//storing index of first occurance of character
		if(count[*(str+i)].count == 1)
			count[*(str+i)].index = i;
	}
	return count;
}

int firstNonRepeating(char *str) {
	countIndex *count = getCharCountArray(str);
	int result = INT_MAX, i;
	for(i=0;i<NO_OF_CHARS;i++)
	{
		//check for character appear only once
		//get the least index of non repeat character
		if(count[i].count ==1 && result > count[i].index)
			result = count[i].index;
	}

	free(count);
	return result;
}

void main() {
	char str[] = "abzddab";
	int index = firstNonRepeating(str);
	if(index == INT_MAX)
		printf("\nString is empty or no non repeating char");
	else
		printf("First non-repeating char is %c", str[index]);
}