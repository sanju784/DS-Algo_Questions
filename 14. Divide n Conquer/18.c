/**
 * Stock Pricing Problem
 *
 * Buy and sell stock in a way to maximize profit
 */
#include <stdio.h>

typedef struct Interval
{
	int buy;
	int sell;
}Interval;

void stockBuySell(int price[], int n)
{
	if(n==1)
		return;
	
	int count = 0;
	
	Interval sol[n/2+1];
	
	int i = 0;
	while(i<n-1)
	{
		//finding next minima
		while((i < n-1) && (price[i+1] <= price[i]))
			i++;
		
		//no profit as array is in decreasing order
		if(i==n-1)
			break;
		
		sol[count].buy = i++;
		
		//finiding next maxima
		while((i < n) && (price[i] >= price[i-1]))
			i++;
		
		sol[count].sell = i-1;
		count++;
	}
	if(count == 0)
		printf("No profit");
	else
	{
		int i;
		for(i=0;i<count;i++)
			printf("Buy on : %d\t Sell on : %d\n", sol[i].buy, sol[i].sell);
	}
}

void main()
{
	int price[] = {100, 180, 260, 310, 40, 535, 695};
	int n = sizeof(price)/sizeof(price[0]);
	
	stockBuySell(price, n);
}