/**
 * Maximum sum submatrix of matrix which has both positive and negative number
 */
 
//This program uses kadane algorithm to get maximum sum subarray of an array
#include <bits/stdc++.h>

using namespace std;

#define R 4
#define C 5

//kadane algorithm to get maximum sum subarray
int kadane(int *arr, int *start, int *finish, int n)
{
	int sum =0, maxSum=INT_MIN, i;
	
	*finish = -1;
	int local_start = 0;
	for(i=0;i<n;i++)
	{
		sum += arr[i];
		if(sum < 0)
		{
			sum = 0;
			local_start = i+1;
		}
		else if(sum > maxSum)
		{
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}
	
	if(*finish != -1)
		return maxSum;
	
	maxSum = arr[0];
	*start = *finish =0;
	for(i=1;i<n;i++)
	{
		if(arr[i] > maxSum)
		{
			maxSum = arr[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}

void findMaxSum(int M[][C])
{
	int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
	
	int left,right, i;
	//to save sum of all coulmuns
	int temp[R];
	int sum, start, finish;
	
	for(left = 0;left <C;left++)
	{
		memset(temp, 0, sizeof(temp));
		
		for(right=left;right<C;right++)
		{
			for(i=0;i<R;i++)
				temp[i] += M[i][right];
			
			sum = kadane(temp, &start, &finish, R);
			
			if(sum>maxSum)
			{
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}
		}
	}
	
	printf("(Top,    Left)  -> (%d, %d)\n", finalTop, finalLeft);
	printf("(Bottom, Right) -> (%d, %d)\n", finalBottom, finalRight);
	printf("Max sum is : %d\n", maxSum);
}

int main()
{
	int M[R][C] = {
					{ 1,  2, -1, -4, -20},
                    {-8, -3,  4,  2,   1},
                    { 3,  8, 10,  1,   3},
                    {-4, -1,  1,  7,  -6}
                    };
 
    findMaxSum(M);
	return 0;
}