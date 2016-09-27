/**
 * Replace all space in String with %20
 */
#include <stdio.h>
#include <string.h>

void replaceSpace(char str[])
{
	int space_count = 0, i, j;
	for(i=0; str[i]; i++)
		if(str[i] == ' ')
			space_count++;
		
	//removing extra spaces at the end
	while(str[i-1] == ' ')
	{
		space_count--;
	    i--;
	}
	
	int new_length = i + space_count*2 + 1;
	
	int index = new_length-1;
	str[index--] = '\0';
	
	//filling from the end of string
	for (j=i-1;j>=0;j--)
	{
		if(str[j] == ' ')
		{
			str[index--] = '0';
			str[index--] = '2';
			str[index--] = '%';
		} else {
			str[index--] = str[j];
		}
	}
}

void main() {
	char str[] = "hello all ";
	printf("%s\n", str);
	replaceSpace(str);
	printf("\n%s", str);
}