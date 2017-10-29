/**
 * Swap bits at Even and Odd position of a number
 */
#include<bits/stdc++.h>
using namespace std;

int swapOddEven(unsigned int x)
{
	//A hexadecimal the value is F(15) represented by 1111(4bits)
	// So in Hexadecimal representation A(10) is represented by (1010)
	//similarly 5(5) is represented by (0101)
	//so in Hexadecimal representation AA...8 times will represent (10101010...32 times)
	//same in 55....8 times will represent (01010101....32 times)
	
	
	//0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0
	//by performing and operation we get all bits at even position
	unsigned int even_bits = x & 0xAAAAAAAA;
	//0x55555555 is a 32 bit number with all odd bits set as 1 and all even bits as 1
	//by performing and operation we get all bits at odd position
	unsigned int odd_bits = x & 0x55555555;
	
	//Right shift all Even bits by 1
	even_bits >>= 1;
	//Left shift all Odd bits by 1
	odd_bits <<= 1;
	
	//joining both odd and even bits
	return (even_bits | odd_bits);
}

int main()
{
	unsigned int x = 23;
	unsigned int res = swapOddEven(x);
	cout<<res;
}