/**
 * Compress a String using count of repeated character
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RLEN 50

char *encode(char *str)
{
	int rLen;
	char count[MAX_RLEN];
	int len = strlen(str);
	
	//The maximum possible size of resulting string can be twice of its length
	char *dest = (char*)malloc(sizeof(char)*(len*2+1));
	
	int i, j=0, k;
	
	for(i=0;i<len;i++)
	{
		dest[j++] = str[i];
		
		rLen = 1;
		while(i+1 < len && str[i] == str[i+1])
		{
			rLen++;
			i++;
		}
		
		//converting integer to string
		sprintf(count, "%d", rLen);
		
		for(k=0; *(count+k); k++)
		{
			dest[j++] = count[k];
		}
	}
	dest[j] = '\0';
	return dest;
}

void main() {
	char str[] = "helloall";
	char *res = encode(str);
	printf("%s", res);
}