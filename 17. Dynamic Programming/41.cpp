/**
 * Maximum size submatrix with all 1's
 */

//This problem is solved by maximum histogram area method

#include <bits/stdc++.h>

using namespace std;

#define R 4
#define C 4

//method to get maximum area of a histogram
int maxHist(int row[])
{
	stack<int> result;
	
	int top_val;
	
	int max_area = 0;
	int area=0;
	
	int i=0;
	while(i<C)
	{
		if(result.empty() || row[result.top()] <= row[i])
			result.push(i++);
		else
		{
			top_val = row[result.top()];
			result.pop();
			area=top_val*i;
			if(!result.empty())
				area= top_val*(i-result.top() -1);
			max_area = max(area, max_area);
		}
	}
	
	while(!result.empty())
	{
		top_val = row[result.top()];
		result.pop();
		area = top_val * i;
		if(!result.empty())
			area = top_val * (i-result.top() - 1);
		max_area = max(area, max_area);
	}
	return max_area;
}

//here we take one row at a time and 
//if current value is 1, then we add each cell value to the previous value
//if current value is 0, then we replace the row value with 0
int maxRectangle(int A[][C])
{
	//getting maximum histogram area of first row
	int result = maxHist(A[0]);
	int i;
	for(i=1;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			//if cell value is 1 then adding it with previous row cell value
			if(A[i][j])
				A[i][j] += A[i-1][j];
		}
		//getting maximum histogram area of current row
		//saving the maximum histogram area of all rows
		result = max(result, maxHist(A[i]));
	}
	return result;
}

int main()
{
	int A[][C] = { {0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0},
                 };
				 
	printf("Area of maximum rectangle is: %d", maxRectangle(A));
	return 0;
}