/**
 * Maximum size square submatrix with all 1's
 */
#include <stdio.h>
#include <stdbool.h>

#define R 6
#define C 5

//minimum of 3 number
int min(int a, int b, int c)
{
	int m = a;
	if(b<m)
		m=b;
	if(c<m)
		m=c;
	return m;
}

void printMaxSubSquare(bool M[R][C])
{
	int i,j;
	
	//Resulting matrix to store sub square matrix value
	int T[R][C];
	
	//To find maximum value in the resulting matrix
	int max_of_t, max_i, max_j;
	
	//The first row and column of resulting matrix will be same as of source matrix
	
	//set first column of T[][] same as M[][]
	for(i=0;i<R;i++)
		T[i][0] = M[i][0];
	
	// set first row of T[][] same as M[][]
	for(j=0;j<C;j++)
		T[0][j] = M[0][j];

	
	for(i=1;i<R;i++)
	{
		for(j=1;j<C;j++)
		{
			//if M[i][j]=1,
			//T[i][j] =  1 + min(T[i-1][j-1], T[i-1][j], T[i][j-1])
			if(M[i][j] == 1)
				T[i][j] = min(T[i][j-1], T[i-1][j], T[i-1][j-1]) + 1;
			//if M[i][j]=0, then T[i][j]=0
			else
				T[i][j] = 0;
		}
	}
	
	//the Resulting matrix size is the maximum value in T[i][j]
    //in this example the maximum value in T[i][j] is 3, 
	//so the resulting matrix is of size 3*3	
	max_of_t = T[0][0]; max_i = 0; max_j = 0;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(max_of_t < T[i][j])
			{
				max_of_t = T[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	printf("Maximum size square sub-matrix is: \n");
	for(i=max_i;i>max_i - max_of_t;i--)
	{
		for(j=max_j;j>max_j-max_of_t;j--)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	bool M[R][C] =  {
					{0, 1, 1, 0, 1}, 
                    {1, 1, 0, 1, 0}, 
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}
					};
                
    printMaxSubSquare(M);
}


/**

T[i][j] =

1. If M[i][j] = 0 , T[i][j] = 0
2. If M[i][j] = 1 , T[i][j] = 1 + min(T[i-1][j-1], T[i-1][j], T[i][j-1])

*/