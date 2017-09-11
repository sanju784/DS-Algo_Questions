/*********************************************
*
*  Find Maximum span in an Array using Stack
*
*/////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

//here index of the array value is added to the stack
void getSpan (int arr[], int span[], int n) {
	stack<int> st;
	st.push(0);
	span[0] = 1;  //span of first element is always 1
	for(int i = 1; i < n; i++) {
		//popping out element from stack which are lower than the current value
		while(!st.empty() && arr[i] >= arr[st.top()])
			st.pop();

		//if stack is empty it means that the current value is greater
		//than all values before it
		//Otherwise the current value is greater than the value of top of stack
		if(st.empty())
		    span[i] = i + 1;
		else
			span[i] = i-st.top();
		
		st.push(i);
	}
}

int main()
{
	int arr[] = {6,3,4,5,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int span[n];
	cout<<"Span List = \n";
	getSpan(arr, span, n);
	for(int i = 0; i < n; i++)
		cout<<span[i]<<"  ";
}
