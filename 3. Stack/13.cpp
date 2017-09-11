/*********************************************
*
*  Largest Rectangle under Histogram
*
*/////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

/**

In this algorithm we add index of array and not array element

1. Add to stack if current element is greater than or equal to the top of the stack
2. Otherwise remove element from the stack and calculate area with below conditions
	a. if(stack is empty)
		area = arr[top]*i
	   else
		   area = arr[top]*(i-s.top()-1)
	b. save the maximum area found
*/
int getArea(int arr[], int n)
{
	int area, max_area=INT_MIN;
	stack<int> s;
	int i=0;
	while(i<n)
	{
		if(s.empty() || arr[i] >= arr[s.top()])
			s.push(i++);
		else
		{
			int tp = s.top();
			s.pop();
			if(s.empty())
				area = arr[tp] * i;
			else
				area = arr[tp] * (i-s.top()-1);
			if(area > max_area)
				max_area = area;
		}
	}
	while(s.empty() == false)
	{
		int tp = s.top();
		s.pop();
		if(s.empty())
				area = arr[tp] * i;
			else
				area = arr[tp] * (i-s.top()-1);
		if(area>max_area)
			max_area = area;
	}
	return max_area;
}

int main()
{
	int arr[] = {3,2,5,6,1,4,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Maximum area = "<<getArea(arr,n);
}
