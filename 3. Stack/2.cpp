#include <bits/stdc++.h>
using namespace std;

int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Prec(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

int infixToPostfix(char* exp)
{
	int i, k;

	stack<char> stack;

	for (i = 0, k = -1; exp[i]; ++i)
	{
		// If the scanned character is an operand, add it to output.
		if (isOperand(exp[i]))
			exp[++k] = exp[i];

		// If the scanned character is an ‘(‘, push it to the stack.
		else if (exp[i] == '(')
			stack.push(exp[i]);

		// If the scanned character is an ‘)’, pop and output from the stack
		// until an ‘(‘ is encountered.
		else if (exp[i] == ')')
		{
			while (!stack.empty() && stack.top() != '(')
			{
				exp[++k] = stack.top();
				stack.pop();
			}
			if (!stack.empty() && stack.top() != '(')
				return -1; // invalid expression
			else
				stack.pop();
		}
		else // an operator is encountered
		{
			while (!stack.empty() && Prec(exp[i]) <= Prec(stack.top()))
			{
				exp[++k] = stack.top();
				stack.pop();
			}
			stack.push(exp[i]);
		}

	}

	// pop all the operators from the stack
	while (!stack.empty())
	{
		exp[++k] = stack.top();
		stack.pop();
	}

	exp[++k] = '\0';
	printf( "%sn", exp );
}

// Driver program to test above functions
int main()
{
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}
