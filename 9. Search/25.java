/*********************************************
*
*  Find two elements in an array such that there sum is k
*
*/////////////////////////////////////////////

import java.io.*;
import java.util.*;

class findksum{
	public static void main(String[] args){
		int arr[] = {1, 3, 8, 9, 4, 2};
		int k = 7;
	    HashSet<Integer> hash = new HashSet<>();
	    for(int i=0;i<arr.length;i++){
	    	hash.add(k-arr[i]);
	    }
	    for(int i=0;i<arr.length;i++){
	    	if(hash.contains(arr[i])) {
	    		System.out.println(arr[i] +" " +(k-arr[i]));
	    		break;
	    	}
	    }
	}
}