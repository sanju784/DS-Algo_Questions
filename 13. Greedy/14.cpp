/**
 * Fractional Knapscak Problem
 */

//compile by g++ -std=c++11 14.cpp

#include <bits/stdc++.h>
using namespace std;

struct Item
{
	int value;
	int weight;
	
	//Constructor
	Item(int value, int weight) : value(value), weight(weight)
	{}
};

//Comparison function to sort Items in decreasing order of val/weight ratio
bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value/a.weight;
	double r2 = (double)b.value/b.weight;
	return r1>r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n)
{
	//sorting value/weight in decreasing order
	sort(arr, arr+n, cmp);
	
	//current weight in knapsack
	int curWeight = 0;
	//Result value in knapsack
	double finalValue = 0.0;
	
	for(int i=0;i<n;i++)
	{
		//selecting element with highest value/weight ratio first
		if(curWeight + arr[i].weight <= W)
		{
			curWeight += arr[i].weight;
			finalValue += arr[i].value;
		//the final weight which does not match any so taking that weight at last and breaking loop
		} else {
			int remain = W - curWeight;
			finalValue += arr[i].value * ((double) remain / arr[i].weight);
			break;
		}
	}
}

int main()
{
	int W = 50;
	Item arr[] = {{60,10}, {100,20}, {120,30}};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Maximum value is "<<fractionalKnapsack(W, arr, n);
	return 0;
}
