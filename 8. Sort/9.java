/*********************************************
*
*  Find a and b from 2 array such that a+b=k
*
*/////////////////////////////////////////////

import java.io.*;
import java.util.*;

class findPair{
	public static void main(String args[]) {
	int arr1[] = {1, 0, -4, 7, 6, 4};
    int arr2[] = {0 ,2, 4, -3, 2, 1};
    int x = 8;
    HashSet<Integer> h = new HashSet<Integer>();
    for(int i=0;i<arr1.length;i++)
    	h.add(arr1[i]);
    for(int i=0;i<arr2.length;i++)
    	if(h.contains(x-arr2[i]))
    		System.out.println((x-arr2[i]) + " " + arr2[i]);
    }
}