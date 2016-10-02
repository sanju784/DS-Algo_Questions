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