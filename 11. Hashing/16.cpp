/**
 * Find first repeating character in a string 
 */

//compile by g++ -std=c++0x 16.cpp

#include <bits/stdc++.h>

using namespace std;

char firstRepeating(string &str) {
	unordered_set<char> h;
	char c;
	for(int i=str.length()-1;i>=0;i--)
	{
		if(h.find(str[i]) != h.end())
			c=str[i];
		else
			h.insert(str[i]);
	}
	return c;
}

int main() {
    string str = "abzddab";
    cout<<firstRepeating(str);
	return 0;
}
