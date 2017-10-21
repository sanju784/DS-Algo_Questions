/**
 * Check duplictes
 */
import java.io.*;
import java.util.*;

class Duplicate
{
	public static void main (String args[])
	{
		int arr[] = {10,5,3,4,5,6};
		printDuplicate(arr);
	}
	
	static void printDuplicate(int arr[])
	{
		HashSet<Integer> set = new HashSet<>();
		for(int i = arr.length-1; i >= 0; i--)
		{
			if(set.contains(arr[i]))
				System.out.println("Duplicate element is " + arr[i]);
			else
				set.add(arr[i]);
		}
	}
}