/**
 * Find minimum window which contains all character of a String
 */
#include <bits/stdc++.h>
#define NO_OF_CHARS 256

using namespace std;

string findSubString(string str, string pat)
{
	int len1 = str.length();
	int len2 = pat.length();
	if(len1 < len2)
	{
		cout<<"No proper window";
		return "";
	}
	
	int hash_str[NO_OF_CHARS] = {0};
	int hash_pat[NO_OF_CHARS] = {0};
	
	for(int i=0;i<len2;i++)
		hash_pat[pat[i]]++;
	
	int start = 0, start_index = -1, min_len = INT_MAX;
	
	int count = 0;
	for(int j=0;j<len1;j++)
	{
		hash_str[str[j]]++;
		
		if(hash_pat[str[j]] != 0 && hash_str[str[j]] <= hash_pat[str[j]])
			count++;
		
		  if(count == len2) {
			
			while(hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]]==0){
				if(hash_str[str[start]] > hash_pat[str[start]])
					hash_str[str[start]]--;
				start++;
		  }
		
		  int len_win = j-start+1;
		  if(min_len > len_win)
		  {
			min_len = len_win;
			start_index = start;
		  }
	    }
	}
	
	if(start_index == -1)
	{
		cout<<"No window";
		return "";
	}
	
	return str.substr(start_index, min_len);
}

int main() {
	string str = "this is test string";
	string pat = "tist";
	cout<<"Smallest window is \n"<<findSubString(str, pat);
    return 0;
}