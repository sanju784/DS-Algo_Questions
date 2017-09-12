/*********************************************
*
*  Find first element that is repeated
*
*/////////////////////////////////////////////

import java.io.*;
import java.util.*;

class FirstRepeat{
	public static void main(String args[]) {
	  int arr[] = {1,6,3,2,3,6,6};
	  printFirstRepeat(arr);
	}

	public static void printFirstRepeat(int arr[]) {
		HashSet<Integer> hash = new HashSet<>();
		int min =-1;
		//checking array from behind and saving the index of last repeating number from back
		//so it will give first repeating number from front
		for(int i = arr.length-1;i>=0;i--){
			if(hash.contains(arr[i]))
				min = i;
			else
				hash.add(arr[i]);
		}
		if(min == -1)
			System.out.println("No repeating element");
		else
			System.out.println("First Repeating element is " + arr[min]);
	}
}

//in c++ using unordered_set
//compile using g++ -std=c++0x file.cpp
/**
void firstR(int arr[], int n)
{
	unordered_set<int> s;
	
	int min = -1;
	for(int i=n-1;i>=0;i--)
	{
		if(s.find(arr[i]) == s.end())
			s.insert(arr[i]);
		else
			min =i;
	}
	
	cout<<min;
}
*/
