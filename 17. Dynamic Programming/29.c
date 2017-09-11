/**
 * Count number of ways parantheses can be placed between boolean operator so that result is always true
 */
#include <stdio.h>
#include <string.h>

int countParanth(char symbol[], char operator[], int n)
{
	int F[n][n], T[n][n];
	int i,j,k,gap,g;
	
	for(i=0;i<n;i++)
	{
		F[i][i] = (symbol[i] == 'F')?1:0;
		T[i][i] = (symbol[i] == 'T')?1:0;
	}
	
	for(gap=1;gap<n;gap++)
	{
		for(i=0, j=gap; j<n; i++,j++)
		{
			T[i][j] = F[i][j] = 0;
			for(g=0;g<gap;g++)
			{
				k=i+g;
				
				int tik = T[i][k] + F[i][k];
				int tkj = T[k+1][j] + F[k+1][j];
				
				if(operator[k] == '&')
				{
					T[i][j] += T[i][k]*T[k+1][j];
					F[i][j] += (tik*tkj - T[i][k]*T[k+1][j]);
				}
				if(operator[k] == '|')
				{
					F[i][j] += F[i][k]*F[k+1][j];
					T[i][j] += (tik*tkj - F[i][k]*F[k+1][j]);
				}
				if(operator[k] == '^')
				{
					T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j];
					F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
				}
			}
		}
	}
	return T[0][n-1];
}

void main()
{
	char symbols[] = "TTFT";
	char operators[] = "|&^";
	int n = strlen(symbols);
	
	printf("Total Paranthesis %d", countParanth(symbols, operators, n));
}