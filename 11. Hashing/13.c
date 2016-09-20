/**
 * Remove characters from a string which are present in other string
 */

#include <stdio.h>
#include <stdlib.h>
#define NO_OF_CHARS 256

//Assuming total characters in C as 256 (considering specail characters and all)
int *getCharCountArray(char *str) {
	int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
	int i;
	for(i=0;i<*(str+i);i++)
		count[*(str+i)]++;
	return count;
}

char *removeChars(char *str, char *mask_str) {
	int *count = getCharCountArray(mask_str);
	int ip_ind = 0, res_ind = 0;
	while(*(str + ip_ind))
	{
		char temp = *(str + ip_ind);
		if(count[temp] == 0)
		{
			*(str + res_ind) = *(str + ip_ind);
			res_ind++;
		}
		ip_ind++;
	}
	*(str+res_ind) = '\0';

	return str;
}

void main()
{
    char str[]       = "teststring";
    char mask_str[]  = "mask";
    printf("%s", removeChars(str, mask_str));
}