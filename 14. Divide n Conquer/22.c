/**
 * Check if an Integer is a Square
 */
#include <stdio.h>
#include <stdbool.h>

bool isSquare(int n)
{
	int i;
	for(i=1;i<n/2;i++)
	{
		if(i*i == n)
			return true;
		if(i*i > n)
			return false;
	}
}

void main()
{
	int n = 16;
	if(isSquare(n))
		printf("%d is Square\n", n);
	else
		printf("%d is not Square\n", n);

	n = 15;
	if(isSquare(n))
		printf("%d is Square\n", n);
	else
		printf("%d is not Square\n", n);
}