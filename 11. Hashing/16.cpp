/**
 * Find first repeating character in a string 
 */

//compile by g++ -std=c++0x 16.cpp

#include <bits/stdc++.h>

using namespace std;

char firstRepeating(string &str) {
	unordered_set<char> h;
	for(int i=0;i<str.length();i++)
	{
		char c = str[i];
		if(h.find(c) != h.end())
			return c;
		else
			h.insert(c);
	}
	return '\0';
}

int main() {
    string str = "abzddab";
    cout<<firstRepeating(str);
	return 0;
}