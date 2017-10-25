/**
 * Check for anagrams in an arrays
 */
#include <bits/stdc++.h>
using namespace std;

#define NO_OF_CHAR 256

//checking if two string are anagram of each other
//using the count sort method
bool isAnagram(string s1, string s2)
{
    //initialize count array as 0
    int count[NO_OF_CHAR] = {0};
    int i;

    //for each character in s1 incrementing count
    //decrementing count for each character in s2
    for(i=0;s1[i] && s2[i]; i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    //checking if length of two string were same or not
    if(s1[i] || s2[i])
        return false;

    //checking if there is any non zero value in array
    for(i=0;i<NO_OF_CHAR;i++)
        if(count[i])
            return false;
    return true;
}

void findAllAnagram(string arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            if(isAnagram(arr[i], arr[j]))
                cout<<arr[i]<<" is anagram of "<<arr[j]<<endl;
    }
}

int main()
{
    string arr[] = {"nwae", "wane", "dog", "god", "gdo", "dica", "acid"};

    //string is a class and all string has a constant size of 32 bytes
    int n = sizeof(arr)/sizeof(arr[0]);

    findAllAnagram(arr, n);
}
